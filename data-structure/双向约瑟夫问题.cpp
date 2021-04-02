#include "stdio.h"
#include "stdlib.h"
typedef struct node{
    int number;
    struct node *link_x;
    struct node *link_y;
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
            p0->link_x = p;
            p0 = p0->link_x;
            p->link_x = head;
        }
        p = head;
        p0 = p->link_x;
        for (int i = 0; i < n; i++){
            p0->link_y = p;
            p0 = p0->link_x;
            p = p->link_x;
        }
        int count = n;
        p = head;
        for (int i = 1; i < k; i++){
            p = p->link_x;
        }
        NODE *p1, *p2;
        p1 = p;
        p2 = p;

        while (count > 0){
            for (int i = 1; i < m; i++){
                p1 = p1->link_x;
                p2 = p2->link_y;
            }
            if(p1->number == p2->number){
                count--;
                printf("%d,", p1->number);
                NODE *p10, *p20;
                p10 = p1->link_y;
                p20 = p2 ->link_x;
                p10->link_x = p20;
                p20->link_y = p10;
                p1 = p20;
                p2 = p10;
            }
            else{
                count -= 2;
                printf("%d-%d,", p1->number, p2->number);
                NODE *p10, *p20;
                p10 = p1->link_y;
                p10->link_x = p1->link_x;
                p10->link_x->link_y = p10;
                p1 = p10->link_x;

                p20 = p2->link_x;
                p20->link_y = p2->link_y;
                p20->link_y->link_x = p20;
                p2 = p20->link_y;
            }
        }
        printf("\n");
    }
}
