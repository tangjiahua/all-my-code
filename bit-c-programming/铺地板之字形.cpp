#include "stdio.h"
#include "math.h"
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i,j,k,d;
		int a=0,b=0;
		int x=1,ans[n][n];
		for(i=0;i<(n-1)*2;i++)						/*i为ab之和；j为循环次数的判断*/
		{
			k=n-fabs(n-1-i);
			if(a==0&&b==0)
			{
				ans[a][b]=x++;
				b++;
				continue;
			}
			if(a>b)
			{
				for(j=0;j<k;j++)
				{
					ans[a][b]=x++;
				
					a--;b++;
					
				}
				a++;
				continue;
			}
			
			if(a<b)
			{
				for(j=0;j<k;j++)
				{
					ans[a][b]=x++;
					b--;a++;
					
				}
				b++;
				continue;
			}
				
		}
		for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					if(j<(n-1)) printf("%2d ",ans[i][j]);
					else printf("%2d\n",ans[i][j]);
				}	
			}
	}
}
