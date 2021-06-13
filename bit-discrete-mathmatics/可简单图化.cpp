#include "stdio.h"
#include "stdlib.h"
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;//这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}
int main(int argc, char const *argv[])
{
    int n, a[3002], i = 0, total = 0;
    scanf("%d",&n);
    int n1 = n;
    while(n1--){
        scanf("%d",&a[i]);
        total = total + a[i];
        i++;
    }
    while(1){
        qsort(a,n,sizeof(a[0]),cmp);
        n1 = a[0];
        total = total - a[0];
        a[0] = 0;
        for(int i = 1; i < n1+1; i++){
            a[i]--;
            if(a[i] < 0)
            {
                printf("no\n");
                return 0;
            }
        }
        total = total - n1;
        // n--;
        if(total == 0){
            printf("yes\n");
            return 0;
        }
    }
    return 0;
}
