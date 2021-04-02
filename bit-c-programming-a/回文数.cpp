#include "stdio.h"
int main()
{
	int n;
	long long int x,y,z;
	int d,num;
	while(scanf("%d",&n)!=EOF)
	{
		
		for(int i=1;i<n;i++)
		{
			
			z=0,d=0;
			x=i*i;
			for(y=x;y>0;y/=10)
				d++;
			y=x;
			for(int j=0;j<d;j++)
			{
				num=y%10;
				y/=10;
				for(int p=0;p<d-j-1;p++)
					num*=10;
				z=z+num;
			}
			if(z==x) printf("%d\n",i);

		}
	}
} 
