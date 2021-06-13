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
    int box[10][2] = {{0, -1}, {1, -1}, {2, -1}, {3, -1}, {4, -1}, {5, -1}, {6, -1}, {7, -1}, {8, -1}, {9, -1}};
    int count = 1;
    NODE *head1;
    head1 = head;
    int flag = 0;

    while(1){
        int n1; 
        NODE *p = (NODE *)malloc(sizeof(NODE));
        n1 = n * 10;

        if (m > n1){
            if(flag == 0){
                while(m > n1){
                    NODE *p1 = (NODE *)malloc(sizeof(NODE));
                    p1->data = 0;
                    p1->next = NULL;
                    head->next = p1;
                    head = p1;
                    n1 = n1 * 10;
                    box[0][1] = 1;
                    count++;
                }
                p->data = n1 / m;
                box[n1/m][1] = count++;
                p->next = NULL;
                head->next = p;
                head = p;
                n = n1 % m;
                flag = 1;
                continue;
            }

            if (box[0][1] == -1){
                p->data = 0;
                box[0][1] = count++;
                p->next = NULL;
                head->next = p;
                head = p;
            }
            else{
                for (int i = 0; i < box[0][1]; i++){
                    head1 = head1->next;
                }
                head->next = head1;
                return;
            }
            
        }
        else if(m <= n1){
            if(n1%m == 0){
                p->data = n1 / m;
                //除尽的话前面应该不会有循环了，
                p->next = NULL;
                head->next = p;
                head = p;
                return;
            }
            else{
                if(box[n1/m][1] == -1){
                    p->data = n1 / m;
                    box[n1/m][1] = count++;
                    p->next = NULL;
                    head->next = p;
                    head = p;
                    n = n1 % m;
                }
                else{
                    for (int i = 0; i < box[n1/m][1]; i++){
                        head1 = head1->next;
                    }
                    head->next = head1;
                    return;
                }
            }
        }
    }
}