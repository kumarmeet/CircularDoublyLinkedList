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

void addItemAfterParticularNode(struct Node *s, int item)
{
    struct Node *n, *p, *t;
    n = createNode(item);

    if(s == NULL)
        printf("List is empty");
    else
    {
        p = s;

        n->next = p->next;
        p->next->prev = n;
        n->prev = p;
        p->next = n;
    }
}

void deleteItemAtParticularNode(struct Node **s, int item)
{
    struct Node *t, *p;

    p = searchItem(*s, item);

    if(s == NULL)
        printf("List is empty");
    else if((*s)->item == item)
    {
        deleteFirstNode(s);
    }
    else if(p->item == item)
    {
        t = p;
        t->prev->next = t->next;
        t->next->prev = t->prev;
        free(p);
    }
    else
        printf("Item not found");

}

void deleteFirstNode(struct Node **s)
{
    struct Node *r;
    r = *s;

    *s = r->next;
    (*s)->prev = r->prev;
    (*s)->prev->next = *s;
    free(r);
}

struct Node* searchItem(struct Node *s, int item)
{
    struct Node *t;

    if(s == NULL)
    {
        printf("List is empty");
        return NULL;
    }
    else
    {
        t = s;

        while(s != t->next)
        {
            if(t->item == item)
                return t;

            t = t->next;
        }
        if(t->item == item)
            return t;
        return NULL;
    }
}

void addItemAtFirst(struct Node **s, int item)
{
    struct Node *n, *t;
    n = createNode(item);
    t = *s;

    *s = n;
    n->prev = t->prev;
    n->next = t;
    t->prev->next = n;
}

void deleteAtLastNode(struct Node *s)
{
    struct Node *r, *t;
    if(s == NULL)
        printf("List is Empty");
    else
    {
        t = s;
        r = s->prev;
        t->prev = r;
        r->prev->next = t;
        free(r);
    }
}

void addItemAfterNode(struct Node **s, int item)
{
    struct Node *n, *r;
    n = createNode(item);

    if(*s == NULL)
    {
        *s = n;
        /*
        why shows error when i write below lines
        n->prev = n->next;
        n->next =  n->prev;
        */
        n->prev = *s; //assigning address
        n->next = *s; //assigning address
    }
    r = *s;
    while(r->next != *s)
        r = r->next;

    r->next = n;
    n->prev = r;
    (*s)->prev = n;
    n->next = *s;
}

void viewList(struct Node *s)
{
    struct Node *t;
    if(s == NULL)
        return;
    else
    {
        t = s;

        while(t->next != s)
        {
            printf("%d ",t->item);
            t = t->next;
        }
        printf("%d ",t->item);
    }
}


struct Node * createNode(int item)
{
    struct Node *n;
    n = (struct Node*)malloc(sizeof(struct Node));
    n->item = item;
    return n;
}

int countItems(struct Node *s)
{
    int i = 1;
    struct Node *t;
    if(s == NULL)
        return 0;
    else
    {
        t = s;

        while(t->next != s)
        {
            i++;
            t = t->next;
        }
        return i;
    }
}
