#include "stdio.h"
int main(){
    int n;
    scanf("%d",&n);
    int n1 = n;
    int a[105][105];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            scanf("%d",&a[i][j]);
        }
    int x[n][2];
    for(int i = 0; i < n; i++){
        x[i][0] = 0;
        x[i][1] = 0;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(a[i][j] == 1){
                x[i][0]++;
                x[j][1]++;
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%d %d\n",x[i][0], x[i][1]);
    }
    return 0;
}