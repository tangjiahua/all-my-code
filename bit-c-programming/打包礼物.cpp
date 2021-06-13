#include "stdio.h"
#include "stdlib.h"
struct _liwu{
    int v;
    int id;
}liwu[100005];
int p[100005][3];
int cmp(const void *p1, const void *p2){
    struct _liwu *c = (struct _liwu*)p1;
    struct _liwu *d = (struct _liwu*)p2;
    return d->v - c->v;
}
int shuchu(int i){
    
    if(p[i][0]!=-1){
        
        shuchu(p[i][0]);
    }
    printf(" %d", liwu[i].id + 1);
    return 0;
}
int main()
{
    int count = 0;
    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &liwu[i].v);
        liwu[i].id = i;
    }
    qsort(liwu, k, sizeof(struct _liwu), cmp);
    //依次代表装着的礼物的下标，一共装着几个礼物，该礼物是否已经被装(0为被装了)
    for (int i = 0; i < k; i++){
        p[i][0] = -1;
        p[i][1] = 0;
        p[i][2] = -1;
    }
    int m = k - 2;
    for (int i = k - 1; i >= 0; i--){
        for (int j = m; j >= 0; j--){
            if(liwu[j].v >= (liwu[i].v*2)){
                count++;
                p[j][0] = i;
                p[j][1] = p[i][1] + 1;
                p[i][2] = 0;
                m = j - 1;
                break;
            }
            if(j == 0 && liwu[j].v < (liwu[i].v*2)){
                goto q;
            }
        }
    }
    

    q:

        printf("%d\n", k - count);
        for (int i = 0; i < k; i++){
            if(p[i][1] == 0 && p[i][2] == -1){//没有被装没有装别人
                printf("1 %d\n",liwu[i].id+1);
                continue;
            }
            if(p[i][0]!=-1 && p[i][2]!=0){//
                printf("%d", p[i][1] + 1);
                shuchu(p[i][0]);
                printf(" %d", liwu[i].id+1);
                putchar('\n');
                continue;
            }
        }
}
