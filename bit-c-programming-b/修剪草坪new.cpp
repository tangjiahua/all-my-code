#include <stdio.h> 
int maxofrow[110], maxofcol[110];  
int caoping[105][105];  

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main ()   
{  
    int n , m, ans = 1;
    scanf("%d %d", &n, &m);  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            scanf("%d", &caoping[i][j]);  
            maxofrow[i] = max(caoping[i][j],maxofrow[i]);  
            maxofcol[j] = max(caoping[i][j],maxofcol[j]);  
        }  
    }  

    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            if (maxofrow[i] > caoping[i][j] && maxofcol[j] > caoping[i][j]) {  
               ans = 0;
            }  
        }  
    }  
    if (ans)   
    {  
       printf("YES\n%d\n",n+m);  
       for(int i = 0; i < n; i++)  
            printf("%d %d R\n", i+1, maxofrow[i]); 
        for(int j = 0; j < m; j++) 
            printf("%d %d C\n", j+1, maxofcol[j]);
    }  
    else {  
         printf("NO\n");  
    }  
}  