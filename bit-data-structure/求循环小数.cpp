#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE * );  
void change( int, int, NODE * );  
  
void output( NODE * head )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<50 )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m;  
    NODE * head;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head );  
    return 0;  
} 

void change( int n, int m, NODE * head ){
    NODE *p, *q;
    int i = 0, x = 0, yushu = 1;
    n = n * 10;
    x = n / m;
    p = head;
    q = (NODE *)malloc(sizeof(NODE));
    q->data = x;
    p->next = q;
    p = q;
    while(yushu && i<50){
        n = n - x * m;
        n = n * 10;
        x = n / m;
        q = (NODE *)malloc(sizeof(NODE));
        q->data = x;
        p->next = q;
        p = q;
        i++;
        yushu = n % m;
    }
    p->next = NULL;
}