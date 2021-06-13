#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct LIST{
    long id;
    char name[15];
    struct LIST *next;
} NODE;

int main(int argc, char const *argv[])
{
    NODE *head, *p, *q, *head2;
    int n, flag = 0, count = 0;
    scanf("%d", &n);

    head =  (NODE *)malloc(sizeof(NODE));
    head->next = NULL;
    q = head;

    for (int i = 0; i < n; i++){
        p = (NODE*)malloc(sizeof(NODE));
        for (int k = 0; k < 15; k++)
            (*p).name[k] = '\0';
        scanf("%ld %s", &p->id, &p->name);
        p->next = NULL;
        q->next = p;
        q = q->next;
    }

    scanf("%d", &n);
    if(n == 0){
        printf("the LIST2 is NULL.\n");
    }
    else{
        for (int i = 0; i < n; i++){
            flag = 0;
            p = (NODE*)malloc(sizeof(NODE));
            //存储这个数据
            for (int k = 0; k < 15; k++)
                (*p).name[k] = '\0';
            scanf("%ld %s", &p->id, &p->name);
            q = head;
            do{
                q = q->next;
                if (q->id == p->id && strcmp(p->name, q->name) == 0){
                    //printf("%8d %15s is not in LIST1\n", p->id, p->name);
                    flag = 1;
                    count++;
                    break;
                }
            } while (q->next != NULL);
            if(flag == 0){
                printf("%8d %s is not in LIST1.\n", p->id, p->name);
            }
        }
        if(count == n){
            printf("the records of LIST2 are all in the LIST1.\n");
        }
    }
}
