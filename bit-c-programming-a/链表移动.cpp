#include <stdio.h>
#include <stdlib.h>
typedef struct numLink
{
    int no;
    struct numLink *next;
}NODE;

NODE *monenode( NODE *head, int m );

void SetLink( NODE *h, int n )
{
    NODE *p=NULL, *q=NULL;
    int i;
    for( i=0; i<n; i++)
    {
        p = (NODE *)malloc(sizeof(NODE));
        p->no = i+1;
        p->next = NULL;
        if( h->next == NULL )
        {
            h->next = p;
            q = p;
        }
        else
        {
            q->next = p;
            q = q->next;
        }
    }
    return;
}

int main( )
{
    int n,m;
    NODE *head=NULL, *q=NULL;
    scanf("%d%d",&n,&m);
    head = (NODE *)malloc(sizeof(NODE));
    head->no = -1;
    head->next = NULL;

    SetLink( head, n );

    q = monenode( head, m ); //来自这里的开始链表移动

    do
    {
        printf("%d ",q->next->no);
        q = q->next;
    }while( q->next != NULL );
    printf("\n");
    return 0;
}

NODE *monenode( NODE *head, int m )
{
  NODE *p, *q, *z;
  p = head;
  while(p->no != m)
    p = p->next;
  q = p;
  while(q->next !=NULL)
    q = q->next;

  q->next = head->next;
  head->next = p->next;
  p->next = NULL;

  return head;
}
