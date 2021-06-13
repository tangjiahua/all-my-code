#include "stdio.h"  
int main()  
{  
    int n,count,i,j,q,l;  
    while(scanf("%d",&n)!=EOF)  
    {  
        q=n*2-1;  
        for(i=0;i<n;i++)  
        {  
            count=0;  
            if(i==0)  
            {  
                for(j=0;j<q;j++)  
                    {  
                        printf("*");  
                      
                    }  
                    printf("\n");  
                continue;  
            }  
            for(j=1;j<q;j++)  
            {  
                  
                if(j-1==i||(q-j)==i)  
                {  
                    putchar('*');  
                    count++;
                    if((i+1)==n&&count==1)
                    {
                    	printf("\n");
                    	break;
                    }
                }  
                else putchar(' ');  
                  
                if(count==2)   
                    {  
                        printf("\n");  
                        break;  
                    }  
            }  
              
        }  
    }  
}  
