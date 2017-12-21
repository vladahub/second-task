#include <stdlib.h>
#include <stdio.h>

struct Duo
{
    int number;
    int isRoot;
    struct Duo* prev;
    struct Duo* next;
} Duo;

struct Duo* new_list()
{
    struct Duo* root = (struct Duo*)malloc(sizeof(struct Duo));
    root->isRoot = 1;
    root->next = NULL;
    root->prev = NULL;
    return root;
}

int list_delete(struct Duo* root)
{
    if(!root)return 1;
    struct Duo* f = root;
    struct Duo* next;
    while (f->next)
    {
        next = f->next;
        free(f);
        f = next;
    }
    free(f);
    return 0;
}

int push (struct Duo* root, int a)
{
    if (!root) return 1;
    struct Duo* prom = root;
    while (prom->next)
    {
        prom = prom->next;
    }
    struct Duo* add = (struct Duo*)malloc(sizeof(struct Duo));
    add->isRoot = 0;
    add->number = a;
    add->next = NULL;
    add->prev = prom;
    prom->next = add;
    return 0;
}

int unshift (struct Duo* root, int a)
{
    if (!root) return 1;
    struct Duo* add = (struct Duo*)malloc(sizeof(struct Duo));
    add->isRoot = 0;
    add->number = a;
    if(root->next)
    {
        add->next = root->next;
        add->prev = root;
        add->next->prev = add;
        root->next = add;
    }
    else
    {
        root->next = add;
        add->prev = root;
    }
    return 0;
}

int shift(struct Duo* root, int* x)
{
    if (!root) return 1;
    if(!root->next)return 1;
    if(root->next->next)
    {
        struct Duo* prom = root->next->next;
        prom->prev = root;
        *x = root->next->number;
        free(root->next);
        root->next = prom;
    }
    else
    {
        *x = root->next->number;
        free(root->next);
        root->next = NULL;
    }
    return 0;
}

int pop (struct Duo* root, int* x)
{
    if (!root) return 1;
    if(!root->next)return 1;

    struct Duo* prom = root;
    while (prom->next)
    {
        prom = prom->next;
    }
    *x = prom->number;
    prom->prev->next = NULL;
    free(prom);
    return 0;
}

void reverse (struct Duo* root)
{
    if (!root) return;
    if (!root->next)return;
    struct Duo* prom = root->next;
    prom->prev = NULL;
    struct Duo* swp;

    while (prom->next)
    {
        swp = prom->next;
        prom->next = prom->prev;
        prom->prev = swp;
        prom = prom->prev;
    }
    prom->next = prom->prev;
    prom->prev = root;
    root->next = prom;
}

int dedup (struct Duo* root, int a)
{
    if (!root) return 1;
    if(!root->next)return 1;

    struct Duo* prom = root;
    int f = 0;
    while (prom->next)
    {
        if ((a == prom -> number) && (f == 0))
        {
            f = 1;
            prom = prom -> next;
        }

        if ((a == prom -> number) && (f > 0))
        {
            prom->prev->next = prom -> next;
            prom -> next -> prev = prom -> prev;
            free(prom);
        }
                prom = prom -> next;
    }

    if ((a == prom -> number) && (f > 0))
        {
            if (prom -> next == NULL)
            {
                prom -> prev -> next = NULL;
                prom -> prev = NULL;
                free(prom);
            }
            else
            {
                prom->prev->next = prom -> next;
                prom -> next -> prev = prom -> prev;
                free(prom);
            }
        }

        if (f == 0)
        {
            printf("no matches\n");
        }

    return 0;
}

void print_list(struct Duo* root)
{
     if (!root -> next)
     {
         return;
     }
     struct Duo* prom = root -> next;
     while (prom->next)
    {
        printf("%d\n", prom -> number);
        prom = prom -> next;
    }
    printf("%d\n", prom -> number);
}

int main()
{
    struct Duo* root = new_list();
    int err;
    int i;
    /*
//err = pop (root, &i);
//err = unshift (root, 0);
    reverse(root);
    err = shift (root, &i);
    err = list_delete (root);
    printf ("%d", i);*/

    int a;
    scanf ("%d", &a);

  push(root, 5);
  push(root, 3);
  push(root, 3);
  push(root, 5);
  push(root, 5);

    dedup(root, a);
   print_list(root);

    return (0);
}
