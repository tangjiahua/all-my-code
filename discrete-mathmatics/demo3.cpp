#include "stdio.h"
int x[3005];
int a[3005][3005];
int n;
void Search(int p){
    if(x[p] == 1){
        return;
    }
    x[p] = 1;
    for(int i = 0; i < n; i++){
        if(a[p][i] == 1){
            Search(i);
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
        }
    
    Search(0);
    for(int i = 0; i < n; i++){
        if(x[i] == 0){
            printf("no\n");
            return 0;
        }
    }
    printf("yes\n");
    return 0;
}
