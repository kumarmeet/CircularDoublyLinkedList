#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int item;
    struct Node *next;
};
struct Node * createNode(int);
void viewList(struct Node*);
struct Node* searchItem(struct Node *, int);
void addItemAfterNode(struct Node**, int);
void addItemAtFirst(struct Node **, int);
void addItemAfterParticularNode(struct Node*,int);
void deleteItemAtParticularNode(struct Node **, int);
void deleteAtLastNode(struct Node*);
void deleteFirstNode(struct Node**);
int countItems(struct Node*);
int menu(void);
void printMetaData(struct Node *);

int main()
{
    struct Node *start = NULL, *p = NULL;
    int item;

    while(1)
    {
        system("cls");
        printMetaData(start);

        switch(menu())
        {
        case 1:
            input(&item);
            addItemAfterNode(&start,item);
            break;
        case 2:
            input(&item);
            addItemAtFirst(&start,item);
            break;
        case 3:
            printf("Check your item in list or not -> ");
            scanf("%d",&item);
            if(p = searchItem(start,item))
            {
                input(&item);
                addItemAfterParticularNode(p,item);
            }
            else
                printf("Item not found");
            break;
        case 4:
            deleteFirstNode(&start);
            printf("First node deleted successfully");
            break;
        case 5:
            deleteAtLastNode(start);
            printf("last node deleted successfully");
            break;
        case 6:
            input(&item);
            if(searchItem(start,item))
                deleteItemAtParticularNode(&start,item);
            else
                printf("Item not exist");
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Enter right choice");
        }
        getch();
    }
    return 0;
}

void printMetaData(struct Node *s)
{
    printf("You have %d items in your list\n", countItems(s));
    printf("You have list Items? %s\n",s == NULL ? "No" : "Yes");
    viewList(s);
}

void input(int *x)
{
    printf("Enter your item -> ");
    scanf("%d",x);
}

int menu()
{
    int n;
    printf("\n1. Add node");
    printf("\n2. Add node at start");
    printf("\n3. Add node after node");
    printf("\n4. Delete first node");
    printf("\n5. Delete last node");
    printf("\n6. Delete particular node");
    printf("\n7. Exit");
    printf("\nEnter your choice -> ");
    scanf("%d",&n);
    return n;
}
