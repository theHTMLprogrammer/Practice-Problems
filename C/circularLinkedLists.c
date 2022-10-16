#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
    struct s *next;
    int num;
} node;

void create(node *s)
{
    node *u = s;
    char ch = 'y';
    while (ch == 'y')
    {
        printf("Enter the value: ");
        scanf("%d", &s->num);
        printf("Do you want to add more nodes? (y/n): ");
        scanf(" %c", &ch);
        if (ch != 'y')
        {
            s->next = u;
        }
        else
        {
            s->next = (node *)malloc(sizeof(node));
            s = s->next;
        }
    }
    printf("Linked List has been created with the start node = %d \n", s);
}

int count(node *s)
{
    node *u = s;
    int c = 0;
    do
    {
        s = s->next;
        c++;
    } while (s != u);
    return c;
}

int find(node *s)
{
    node *u = s;
    int pos = 1, val;
    printf("Enter the number you want to search: ");
    scanf("%d", &val);
    do
    {
        if (s->num == val)
        {
            return pos;
        }
        s = s->next;
        pos++;
    } while (s != u);
    return -1;
}

void print(node *s)
{
    node *u = s;
    printf("Elements in the linked list are: ");
    do
    {
        printf("%d ", s->num);
        s = s->next;
    } while (s != u);
    printf("\n");
}

node *insert(node *s)
{
    int pos, c = 1;
    node *t, *u = s;
    t = (node *)malloc(sizeof(node));
    if (t == NULL)
    {
        printf("Overflow");
        return s;
    }
    printf("Enter the value you want to insert: ");
    scanf("%d", &t->num);
    printf("Enter the position at which you want to insert this number: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        t->next = s;
        do
        {
            s = s->next;
        } while (s->next != u);
        s->next = t;
        return t;
    }
    if (pos == count(s) + 1)
    {
        t->next = u;
        do
        {
            s = s->next;
        } while (s->next != u);
        s->next = t;
        return u;
    }
    if (pos > 1 && pos < count(s) + 1)
    {
        while (c != pos - 1)
        {
            s = s->next;
            c++;
        }
        t->next = s->next;
        s->next = t;
        return u;
    }
    printf("You entered a wrong value for position!!! \nNo value inserted!!!\n");
}

node *delete (node *s)
{
    int pos, c = 1;
    node *t, *u = s;
    printf("Enter the postion which you want to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        t = u->next;
        do
        {
            s = s->next;
        } while (s->next != u);
        s->next = u->next;
        free(u);
        return t;
    }
    if (pos == count(s))
    {
        while (c != pos - 1)
        {
            s = s->next;
            c++;
        }
        t = s->next;
        s->next = u;
        free(t);
        return u;
    }
    if (pos > 1 && pos < count(s))
    {
        while (c != pos - 1)
        {
            s = s->next;
            c++;
        }
        t = s->next;
        s->next = t->next;
        free(t);
        return u;
    }
    printf("You entered a wrong postion for deletion!!! \nNothing deleted!!!\n");
}

void main()
{
    node *start = (node *)malloc(sizeof(node));
    char ch;
    int pos;
    while (1)
    {
        printf("Case 1: create\n");
        printf("Case 2: count\n");
        printf("Case 3: find\n");
        printf("Case 4: print\n");
        printf("Case 5: insert\n");
        printf("Case 6: delete\n");
        printf("Case 7: Exit\n");
        printf("Enter you choice: ");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            create(start);
            break;
        case 2:
            printf("Number of elements in the linked list = %d \n", count(start));
            break;
        case 3:
            pos = find(start);
            if (pos == -1)
            {
                printf("Element not found!!!\n");
            }
            else
            {
                printf("Element found at position: %d \n", pos);
            }
            break;
        case 4:
            print(start);
            break;
        case 5:
            start = insert(start);
            break;
        case 6:
            start = delete (start);
            break;
        case 7:
            return;
        }
    }
}