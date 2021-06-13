#include "stdio.h"
#include <stdlib.h>
struct node
{
  char ch;
  struct node *next;
};

typedef struct node NODE;

int main()
{
   NODE *p, *head, *q, *k;
   head = (NODE*)malloc(sizeof(NODE));
   head->next = NULL;
   head->ch = -1;

   char a;
   int count = 0;
   for(int i = 0; i<2; i++)
   {
     while(a = getchar())
     {
       if(a == ' ') continue;
       if(a == '\n') break;
       if(i == 0)
       {
         k = (NODE*)malloc(sizeof(NODE));
         k->ch = a;
         q = head;
         while(q->next != NULL)
          q = q->next;
         q->next = k;
         k->next = NULL;
       }
       else
       {
         count = 0;
         k = (NODE*)malloc(sizeof(NODE));
         k->ch = a;
         q = head;
         while(q->next != NULL)
         {
		 	if(q->next->ch <= a)
		 	{
	            if(q->ch == a || q->next->ch == a)
	            {
	            	count = 1;
	            	break;
	            }
         	   	
		 	}
		 	if(q->next->ch >a && q->ch <a) break;
			q = q->next;
			
         }
        if(q->ch == a)
            count = 1;

         if(count == 1) continue;
         if(q->next != NULL)
         {
           k->next = q->next;
           q->next = k;
         }
         else
         {
           k->next = NULL;
           q->next = k;
         }
       }
     }
   }


   p = head->next;
   while(p->next != NULL)
   {
   	putchar(p->ch);
   	putchar(' ');
   	p = p->next;
   }
  putchar(p->ch);
  putchar('\n');


}
