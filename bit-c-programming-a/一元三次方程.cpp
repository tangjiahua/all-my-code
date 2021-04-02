#include "stdio.h"
#include "math.h"
int main()
{
	int T,count;
	while(scanf("%d",&T)!=EOF)
	{
		for(int i=0;i<T;i++)
		{
			int a,b,c,d;
			scanf("%d %d %d %d",&a,&b,&c,&d);
			a=3*a; b=2*b; c=c; int delta;
			double x1,x2,x;
			
			
			if(a==0&&b==0)  
            {  
                printf("Impossible\n");  
                continue;  
            }  
            else if(a==0&&b!=0)  
            {  
                x=(double)((double)(-c)/b); 
				if(a*x*x*x+b*x*x+c*x+d==0) printf("1\n");
				else printf("2\n");
                continue;  
            }  
            else   
            {  
                delta=b*b-4*a*c;  
                if(delta==0)  
                {  
                    printf("1\n");  
                    continue;  
                }  
                if(delta>0)  
                {  
                    x1=(double)(-b+sqrt(delta))/(2*a);  
                    x2=(double)(-b-sqrt(delta))/(2*a);  
                   	if((a*x1*x1*x1+b*x1*x1+c*x1+d)*(a*x2*x2*x2+b*x2*x2+c*x2+d)<0) printf("3\n");
                   	if((a*x1*x1*x1+b*x1*x1+c*x1+d)*(a*x2*x2*x2+b*x2*x2+c*x2+d)>0) printf("1\n");
                    continue;  
                }  
                if(delta<0)  
                {  
                    printf("1\n");  
                    continue;  
                }  
            }
			
		}
	}
}
