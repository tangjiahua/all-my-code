#include "stdio.h"
int px(int x,int n);
int main()
{
	int x,n,y;
	while(scanf("%d %d",&x,&n)!=EOF)
	{
		printf("%d\n",px(x,n));
	}
}

int px(int x,int n)
{
	if(n==1) return x;
	else return (x*px(1-x,n-1));
} 
