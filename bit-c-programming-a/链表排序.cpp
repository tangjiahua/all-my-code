#include "stdio.h"
#include "stdlib.h"

struct node
{   int data;
    struct node * next;
} ;

typedef struct node NODE;
typedef struct node * PNODE;
void outlist( PNODE );
int sortlist( PNODE h, int num );
int main ( )
{   int num=1;
    PNODE head;

    head = (PNODE)malloc( sizeof(NODE) );
    head->next = NULL;
    head->data = -1;

    while ( num!=0 )
    {   scanf("%d", &num);
        if ( num!=0 )
            sortlist( head, num);
    }
    outlist( head );
    return 0;
}

void outlist( PNODE head )
{   PNODE p;
    p = head->next;
    while ( p != NULL )
    {   printf("%d\n", p->data);
        p = p->next;
    }
}


int sortlist( PNODE h, int num )
{   PNODE p, q;
    p = (PNODE)malloc( sizeof(NODE) );
    p->data = num;
    q = h;
    while(q->next !=NULL){
      if(p->data < q->next->data && p->data >=q->data) break;
      else q = q->next;
    }
    if(p->data == q->data) ;
    else {
    p->next = q->next;
    q->next = p;	
    }
}
