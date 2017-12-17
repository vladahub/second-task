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
} Square;

struct Square* new_square()
{
    struct Square* root = (struct Square*)malloc(sizeof(struct Square));
    root->next = NULL;
    root->prev = NULL;
    return root;
}

int add_square (struct Square* root, int x, int y, char color, int m);
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
    return 0;
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
            scanf("%c", sign);
            int err = add_square(root, i, j, sign, m);
        }
    }

    free(path);
    return 0;
}
