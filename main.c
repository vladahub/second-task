#include <stdio.h>
#include <stdlib.h>

typedef struct rec {
    char name[50];
    char number[50];
    struct record* next;
}rec;

rec* create_rec(char name[], char number[])
{
rec* pstr =(rec*) malloc(1 * sizeof(rec));
strcpy(pstr->number, number);
strcpy(pstr->name, name);
pstr->next = NULL;
return pstr;


void find_rec(rec* record, char* strname)
{
    while(strcmp(strname, record -> name) != 0 && (record -> next != NULL))
    {
        record = record -> next;
    }
    if (strcmp(strname, record -> name) != 0)
    {
        printf("NO");
        return 0;
    }
    printf("%s\n", record -> number);
    return 0;
}

void insert_into_list(rec* man, char* maname, char* manumber)
{
    while (man -> next != NULL)
    {
        if (strcmp(man -> name, maname) == 0)
        {
            char old[50];
            strcpy(old, man -> number);
            strcpy(man -> number, manumber);
            printf("Changed. Old value = ", "&s\n", old);
            return 0;
        }
        man = man -> next;
    }
    if ((strcmp(man -> name, maname) == 0) && (man -> next == NULL))
    {
            char old[50];
            strcpy(old, man -> number);
            strcpy(man -> number, manumber);
            printf("Changed. Old value = ", "&s\n", old);
            return 0;
    }
    create_rec(maname, manumber);
}
int main()
{
    char rootname, rootnumber;
    rec* root = create_rec(rootname, rootnumber);

    char insert = "I";
    char find = "F";
    char str[100];
    int i = 0, j = 0;
    char com[10];

    FILE* f = fopen("input.txt", "r");
    if (f == NULL) { printf("file not found\n"); return -1;}

    while (fgets(str, 100, f))
    {
        while (str[i] != ' ')
        {
            com[i] = str[i];
            i++;
        }
        i++;
        if (strcmp(com[0], find) == 0)
        {
            char name1[50];
            while (str[i] != "\n")
            {
                name1[j] = str[i];
                i++;
                j++;
            }
            name1[j] = "\0";
            find_rec(root, name);
        }
        if (strcmp(com[0], insert) == 0)
        {
            j = 0;
            char name2[50];
            while (str[i] != " ")
            {
                name2[j] = str[i];
                i++;
                j++;
            }
            name2[j] = "\0";
            i++;
            j = 0;

            char strnumber[50];
            while (str[i] != "\n")
            {
                strnumber[j] = str[i];
                i++;
                j++;
            }
            strnumber[j] = "\0";
            insert_into_list(root, name2, strnumber);

        }
    }
    fclose(f);
    free(pstr);
    return 0;
}
