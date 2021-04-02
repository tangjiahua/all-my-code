#include <stdio.h>  
#define max(a,b) (a>b?a:b)  
#define bool int  
#define true 1  
#define false 0  
int maxrow[110], maxcol[110];  
int a[110][110];  
   
int main ()   
{  
    int n , m;  
    scanf("%d %d", &n, &m);  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            scanf("%d", &a[i][j]);  
            maxrow[i] = max(a[i][j],maxrow[i]);  
            maxcol[j] = max(a[i][j],maxcol[j]);  
        }  
    }  
    bool isok = true;  
    for (int i = 0; i < n; ++i) {  
        for (int j = 0; j < m; ++j) {  
            if (maxrow[i] > a[i][j] && maxcol[j] > a[i][j]) {  
               isok = false;  
            }  
        }  
    }  
    if (isok)   
    {  
       printf("YES\n");  
       printf("%d\n",n+m);   
      
       for(int i = 0; i < n; i++)  
       {  
              
            printf("%d %d R\n", i+1, maxrow[i]);  
  
       }  
          
        for(int j = 0; j < m; j++)  
       {  
  
                    printf("%d %d C\n", j+1, maxcol[j]);  
  
       }  
         
         
    }  
    else {  
         printf("NO\n");  
    }  
    return 0;  
}  