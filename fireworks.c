#include <stdio.h>
#include <stdlib.h>

struct firework
{
    int rad;
    int cost;
    char name[100];
    struct firework* prev;
    struct firework* next;
} firework;

struct point
{
    int x;
    int y;
    struct point* prev;
    struct point* next;
} point;

struct firework* new_list()
{
    struct firework* root = (struct firework*)malloc(sizeof(struct firework));
    root->next = NULL;
    root->prev = NULL;
    return root;
}

int push (struct firework* root, int radf, int costf, char* name)
{
    if (!root) return 1;
    struct firework* prom = root;
    while (prom->next)
    {
        prom = prom->next;
    }
    struct firework* add = (struct firework*)malloc(sizeof(struct firework));
    add->rad = radf;
    add->cost = costf;
    strcpy(add->name, name);
    add->next = NULL;
    add->prev = prom;
    prom->next = add;
    return 0;
}

int pushpoint (struct point* rootpoint, int x, int y)
{
    if (!rootpoint) return 1;
    struct point* prom = rootpoint;
    while (prom->next)
    {
        prom = prom->next;
    }
    struct point* add = (struct point*)malloc(sizeof(struct point));
    add->x = x;
    add->y = y;
    add->next = NULL;
    add->prev = prom;
    prom->next = add;
    return 0;
}

void find(struct point* rootpoint)
{
    if (!rootpoint) return 1;
    if (!rootpoint -> next) return 1;

    struct point* prom = rootpoint -> next;
    int minx = prom -> x;
    int maxx = prom -> x;

    int miny = prom -> y;
    int maxy = prom -> y;
    prom = prom -> next;
    while (prom -> next)
    {
        if (prom -> x <= minx)
        {
            minx = prom -> x;
        }
        if (prom -> x >= maxx)
        {
            maxx = prom -> x;
        }

        if (prom -> y <= miny)
        {
            miny = prom -> y;
        }
        if (prom -> y >= maxy)
        {
            maxy = prom -> y;
        }
        prom = prom -> next;
    }
    if (prom -> x <= minx)
        {
            minx = prom -> x;
        }
        if (prom -> x >= maxx)
        {
            maxx = prom -> x;
        }

        if (prom -> y <= miny)
        {
            miny = prom -> y;
        }
        if (prom -> y >= maxy)
        {
            maxy = prom -> y;
        }
    float midx = minx + (maxx - minx) / 2;
    float midy = miny + (maxy - miny) / 2;

    pushpoint(rootpoint, midx, midy);
}

void QuickSort(struct firework *a, int begin, int end)
{
    int l = begin;
    int r = end;

    struct firework middle = a[(begin + end) / 2];

    do
    {
        while (a[l].rad < middle.rad) l++;
        while (middle.rad < a[r].rad) r--;

        if (l <= r)
        {
        swap(a[l], a[r]);
        l++;
        r--;
        }
    }

    while (l <= r);

    if (r > begin)
    QuickSort(a, begin, r);

    if (l < end)
    QuickSort(a, l, end);

    }

void fire(struct firework* root, struct point* rootpoint, int bud)
{
    struct point* tmp = rootpoint;
    while (1)
    {
        if (tmp -> next == NULL)
        {
            int x = tmp -> x;
            int y = tmp -> y;
            break;
        }
    }

    struct firework* prom = root;
    while(root -> next)
    {

    }
}

int main()
{
    struct firework* root = new_list();
    struct point* rootpoint = new_list();

    int bud;
    scanf("%d", &bud);

    FILE* f = fopen("options.txt", "r");
    if (f == NULL) { printf("file not found\n"); return -1;}

    char str[200];
    char radius[5];
    char coststr[10];
    char namestr[100];

    int radnum;
    int costnum;
    int i, j;

    struct firework fireworks[100];

    while (fgets(str, 500, f))
    {
        while (str[i] != ' ')
        {
            radius[i] = str[i];
            i++;
        }
        radnum = atoi(radius);
        i++;

        while (str[i] != ' ')
        {
            coststr[i] = str[i];
            i++;
        }
        costnum = atoi(coststr);
        i++;
        while (str[i] != '\n')
        {
            namestr[i] = str[i];
            i++;
        }
        str[i] = '\0';

        push(root, radnum, costnum, namestr);
        fireworks[j].rad = radnum;
        fireworks[j].cost = costnum;
        fireworks[j].name = namestr;
        j++;

    }

    QuickSort(fireworks[100], 0, j - 1);

    FILE* p = fopen("addresses.txt", "r");
    if (p == NULL) { printf("file not found\n"); return -1;}

    int a, b;
    char strpoint[500];
    while (fgets(strpoint, 500, p))
    {
        fscanf(p, "%d %d", &a, &b);
        pushpoint(rootpoint, a, b);
    }

    find(rootpoint);
    fire(root, rootpoint, bud);

    fclose(p);
    fclose(f);
    return 0;
}
