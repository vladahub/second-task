#include <stdio.h>
#include <stdlib.h>

struct Square
{
    struct Square* next;
    struct Square* prev;

    struct Square* left;
    struct Square* right;
    struct Square* up;
    struct Square* down;

    int x;
    int y;
    char color;

    int dleft;
    int dright;
    int dup;
    int ddown;
} Square;

struct Square* new_square()
{
    struct Square* root = (struct Square*)malloc(sizeof(struct Square));
    root->next = NULL;
    root->prev = NULL;
    return root;
}

int add_square (struct Square* root, int x, int y, char color, int m)
{
    if (!root) return 1;
    struct Square* prom = root;
    while (prom->next)
    {
        prom = prom->next;
    }
    struct Square* add = (struct Square*)malloc(sizeof(struct Square));

        add->left = NULL;
        add->right = NULL;
        add->up= NULL;
        add->down = NULL;

    if (color == '.')
    {
        if (prom->color == '.')
        {
            add->left = prom;
            prom->right = add;
        }

        if (x > 0)
        {
            struct Square* tmp = prom;
            int i;
            for(i = 1; i < m; i++)
            {
                tmp = tmp->prev;
            }
        }
    }

    add->x = x;
    add->y = y;
    add->color = color;
    add->next = NULL;
    add->prev = prom;
    prom->next = add;

    add->dleft = 0;
    add->dright = 0;
    add->dup = 0;
    add->ddown = 0;
    return 0;
}

int* pathfinder(struct Square* root, int* path, int n, int m)
{
    struct Square* prom = root -> next;
    int direction = 0;

    while((prom -> x != n) && (prom -> y != m))
    {
        if ((prom -> dright = 0) && (prom -> right))
        {
            prom -> dright = 1;
            printf(prom -> x, prom -> y);
            prom = prom ->right;
            break;
        }
        if ((prom -> ddown = 0) && (prom -> down))
        {
            prom -> ddown = 1;
            printf(prom -> x, prom -> y);
            prom = prom ->down;
            break;
        }
        if ((prom -> dleft = 0) && (prom -> left))
        {
            prom -> dleft = 1;
            printf(prom -> x, prom -> y);
            prom = prom ->left;
            break;
        }
        if ((prom -> dup = 0) && (prom -> up))
        {
            prom -> dup = 1;
            printf(prom -> x, prom -> y);
            prom = prom ->up;
            break;
        }
    }

    return path;
}
int main()
{
    int n;
    int m;
    int i;
    int j;
    char sign;

    scanf("%d %d", &n, &m);

    int* path = (int*)malloc((sizeof(int*) * n * m));

    struct Square* root = new_square();


    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            sign = getchar();
            int err = add_square(root, i, j, sign, m);
        }
        sign = getchar();

    }

    path = pathfinder(root, path, n, m);

    free(path);
    return 0;
}
