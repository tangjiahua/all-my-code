#include "stdio.h"
int main()
{
	int n,a[1000],i,q=0;
	float lv;
	while(scanf("%d",&n)!=EOF)
	{
		q=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]>=80)
			{
				q++;
			}
			
		}
		lv=100*(float)q/(float)n;
		printf("%.2f",lv);
		printf("%%\n");
	}
}
