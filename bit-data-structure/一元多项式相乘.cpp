#include "stdio.h"
#include "stdlib.h" 
  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
void multiplication(NODE *head1, NODE *head2, NODE *head3){
    NODE *p1, *p2, *p3,*p3_pre, *pnew, *start;
    int flag = 0;//x为系数 y为指数
    p1 = head1->next;
    while(p1 != NULL){
        p2 = head2->next;
        start = head3;
        while(p2 != NULL){
            pnew = (NODE *)malloc(sizeof(NODE));
            pnew->coef = p2->coef * p1->coef;
            pnew->exp = p2->exp + p1->exp;
            if(pnew->coef == 0){
                p2 = p2->next;
                continue;
            }
            flag = 0;
            p3 = start->next;
            p3_pre = start;
            while(p3 != NULL){
                if(p3->exp < pnew->exp){
                    p3 = p3->next;
                    p3_pre = p3_pre->next;
                    continue;
                }
                else if(p3->exp == pnew->exp){
                    p3->coef += pnew->coef;
                    if(p3->coef == 0){
                        p3_pre->next = p3->next;
                    }
                    start = p3_pre;
                    flag = 1;
                    break;
                }
                else{
                    p3_pre->next = pnew;
                    pnew->next = p3;
                    flag = 1;
                    start = p3_pre;
                    break;
                }
            }
            if(flag == 0){
                p3_pre->next = pnew;
                pnew->next = NULL;
                start = p3_pre;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    if(head3->next == NULL){
        pnew = (NODE *)malloc(sizeof(NODE));
        pnew->coef = 0;
        pnew->exp = 0;
        head3->next = pnew;
        pnew->next = NULL;
    }
}

int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
     head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  
