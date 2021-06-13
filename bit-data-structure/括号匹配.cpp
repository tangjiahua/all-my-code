#include "stdio.h"
#include "stdlib.h"

typedef struct list{
    char ch;
    struct list *next;
} NODE;

int main(int argc, char const *argv[])
{
    char kuohao, check;
    int flag = 0;
    NODE *head, *p, *q, *q1;
    p = (NODE *)malloc(sizeof(NODE));
    p->ch = '\0';
    p->next = NULL;
    head = p;
    q = head;

    while((kuohao = getchar()) != '\n'){
        if(kuohao != '(' && kuohao != ')' && kuohao != '[' && kuohao != ']')
            continue;
        if(kuohao == '(' || kuohao == '['){
            p = (NODE *)malloc(sizeof(NODE));
            p->ch = kuohao;
            p->next = q->next;
            q->next = p;
        }
        else{
            if(q->next == NULL){
                flag = 1;
                printf("Match false!\n");
                break;
            }
            else{
                if((q->next->ch == '(' && kuohao == ')') || (q->next->ch == '[' && kuohao == ']')){
                    q1 = q->next;
                    q->next = q->next->next;
                    free(q1);
                }
                else{
                    flag = 1;
                    printf("Match false!\n");
                    break;
                }
            }
        }
    }
    if(flag == 0 && head->next != NULL){
        printf("Match false!\n");
    }
    else if(flag == 0 && head->next == NULL){
        printf("Match succeed!\n");
    }
    return 0;
}
