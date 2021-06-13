#include "stdio.h"
#include "string.h"
#include "stdlib.h"
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;//这是从小到大排序，若是从大到小改成： return *(int *)b-*(int *)a;
}
int main(){
    int n, k;
    scanf("%d %d",&n, &k);
    double cable[10005];
    for(int i = 0; i < n; i++){
        scanf("%lf",&cable[i]);
    }
    qsort(cable, n, sizeof(cable[0]), cmp);
    double x = 0, y = cable[0], mid = cable[n-1], mid1 = cable[n-1];
    mid1 = (double)(((int)(mid1*100))/100.0);
    int count = 0;
    int p = 8500;
    while(p--){
        for(int i = 0; i < n; i++){
            count = count + (int)(cable[i]/mid1);
        }
        if(count > k){
            x = mid;
            mid = (x+y)/2.0;
            mid1 = mid;
            mid1 = (double)(((int)(mid1*100))/100.0);
            count = 0;
        }
        else if(count < k){
            y = mid;
            mid = (x+y)/2.0;
            mid1 = mid;
            mid1 = (double)(((int)(mid1*100))/100.0);
            count = 0;
        }
        else{
            break;
        }
    }
    printf("%.2lf\n",mid1);
}