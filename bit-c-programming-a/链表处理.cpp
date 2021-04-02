#include <stdio.h>
#include <stdlib.h>

typedef struct sdata
{  int num;
   struct sdata *next;
} SNODE;

void movenode( SNODE *, int );

void setlink( SNODE * head, int n )
{
    SNODE *p;

    while ( n > 0 )
    {   p = ( SNODE * ) malloc( sizeof( SNODE ) );
        p->num = n;
        p->next = head->next;
        head->next = p;
        n --;
    }
}

void outlink( SNODE * head )
{
    while( head->next != NULL )
    {
        head = head->next;
        printf( "%d,", head->num );
    }
    return;
}

int main( )
{   int n, m;
    SNODE * head = NULL;

    scanf("%d%d", &n, &m );
    head = ( SNODE * ) malloc( sizeof( SNODE ) );
    head->num = -1;
    head->next = NULL;
    setlink( head, n );

    movenode( head, m );   /* This is waiting for you. */

    outlink( head );
    printf("\n");
    return 0;
}

void movenode( SNODE * head, int n)
{
  SNODE *p, *q, *m, *l;
  int i = 0;
  l = head;
  p = head;
  m = head;
  if(n == 1 || n == 0) return ;
  while(l->next != NULL)
  	{
  		l = l->next;
  		i++;
  	}
	if(n > i) return ;
  while(p->num != n)
    p = p->next;
  q = head->next;
  while(m->next->num != n)
    m = m->next;
  m->next = p->next;
  head->next = p;
  p->next = q;
}
