#include "stdio.h"
#include "stdlib.h"
#include "math.h"
int n, m;
int list[40];
int result;
void build(int n, int m){
    if(n == 0){
        return;
    }
    if(m == 0){
        if(n>0){
            result++;
        }
        return;
    }
    if(n >= list[m]+1){
        result += list[m];
        return;
    }
    int maxd = (int)(log(n+1)/log(2))-1;
    while(maxd > m||n-list[maxd+1]+1 < m-maxd){
        maxd--;
        if(maxd < 0) return;
    }
    result += list[maxd];
    if(maxd == m) return;
    build(n-list[maxd+1]+1-m+maxd, maxd);
}

int main(){
    list[0] = 1;
    for(int i = 1; i < 40; i++){
        list[i] = list[i-1]*2;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        result = 0;
        build(n, m);
        printf("%d\n",result);
    }
    return 0;
}