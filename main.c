#include <stdio.h>
#include <stdlib.h>

struct bkt
{
    int number;
    char element;
    struct bkt* prev;
    struct bkt* next;
} bkt;

struct bkt* new_list()
{
    struct bkt* root = (struct bkt*)malloc(sizeof(struct bkt));
    root->next = NULL;
    root->prev = NULL;
    return root;
}

void print_list(struct bkt* root)
{
     if (!root -> next)
     {
         return;
     }
     struct bkt* prom = root -> next;
     while (prom->next)
    {
        printf("%c", prom -> element);
        prom = prom -> next;
    }
}
int push (struct bkt* root, char bracket)
{
    if (!root) return 1;
    struct bkt* prom = root;
    while (prom->next)
    {
        prom = prom->next;
    }
    if ((bracket == '(') || (bracket == '{'))
        {
            struct bkt* add = (struct bkt*)malloc(sizeof(struct bkt));
            add -> element = bracket;
            add->next = NULL;
            add->prev = prom;
            prom->next = add;
            return 0;
        }
    if (bracket == ')')
    {
        if (prom -> element == '(')
            {

                pop(root, prom);
                return 0;
            }
            else return 1;
    }
    if (bracket == '{')
    {
        if (prom -> element == '}')
            {
                pop(root, prom);
                return 0;
            }
            else return 1;
    }

    return 1;
}

int pop (struct bkt* root, struct bkt* tmp)
{
    if (!root) return 1;

    if (!tmp -> next)
        {
            tmp -> prev -> next = NULL;
            free(tmp);
            return 0;
        }
    struct bkt* prom = root;
    while (prom -> next)
    {
        if (prom == tmp) break;
        else prom = prom -> next;
    }

    prom->prev->next = prom -> next;
    prom -> next -> prev = prom -> prev;
    free(prom);
    return 0;
}
int main()

{
    char word;

    struct bkt* root = new_list();
    word = getchar();

    if ((word == '}') || (word == ')'))
        {
            printf("wrong");
            return;
        }

    while (word != "\n")
    {
        if (push(root, word) != 0)
        {
            printf("wrong");
            return;
        }

        word = getchar();

    }

    print_list(root);
        printf("%c",  root -> next -> element);
    printf((root->next)?"wrong":"right");


    return 0;
}
