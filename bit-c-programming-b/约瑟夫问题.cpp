#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int number;
    struct node *link;
} NODE;
int main(int argc, char const *argv[])
{
    int n, k, m;
    scanf("%d,%d,%d", &n, &k, &m);
    if(n<1||k<1||m<1){
        printf("n,m,k must bigger than 0.\n");
    }
    else if(k>n){
        printf("k should not bigger than n.\n");
    }
    else{
        NODE *head;
        NODE *p;
        NODE *p0;
        p0 = (NODE*)malloc(sizeof(NODE));
        head = p0;
        p0->number = 1;
        for (int i = 2; i <=n; i++){
            p = (NODE *)malloc(sizeof(NODE));
            p->number = i;
            p0->link = p;
            p0 = p0->link;
            p->link = head;
        }

        p = head;
        for (int i = 0; i < k-1; i++){
            p = p->link;
        }
        int count = n, count2 = 0;
        while(count > 0){
            for (int i = 0; i < m-1; i++){
                p = p->link;
            }
            p0 = p;
            while(p0->link != p){
                p0 = p0->link;
            }
            if(count2 == 10){
                if(count == 1){
                    printf("%d\n", p->number);
                    p0->link = p->link;
                    count2++;
                    count--;
                    continue;
                }
                putchar('\n');
                printf("%d ", p->number);
                count2 = 1;
                p0->link = p->link;
                count--;
            }
            else if(count2 == 9){
                if(count == 1){
                    printf("%d\n", p->number);
                    p0->link = p->link;
                    count2++;
                    count--;
                    continue;
                }
                printf("%d", p->number);
                count2++;
                p0->link = p->link;
                count--;
            }
            else{
                if(count != 1){
                    printf("%d ", p->number);
                    p0->link = p->link;
                    count2++;
                    count--;
                }
                else{
                    printf("%d\n", p->number);
                    p0->link = p->link;
                    count2++;
                    count--;
                }
                
            }
            p = p->link;
        }
    }
}
