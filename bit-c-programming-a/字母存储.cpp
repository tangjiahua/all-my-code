#include "stdio.h"
int main()
{
  typedef struct node
  {
    char ch;
    struct node *next;
  } NODE;
  NODE *head, *p, *q;
  NODE s1, s2;
  p = (NODE*)malloc(sizeof(NODE));
  p->next = NULL;
  head = p;
  p = (NODE*)malloc(sizeof(NODE));
  char a;
  while(scanf("%c",&a)!='\n')
  {
    p->ch = a;
    p = p->next;
  }
}
