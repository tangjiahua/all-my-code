#include "stdio.h"
int main()
{
	long int need,n1,n5,n10,n20,n50,n100,m1,m5,m10,m20,m50,m100;/*n为需要的 m为持有的*/ 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld%ld%ld%ld%ld%ld%ld",&need,&m1,&m5,&m10,&m20,&m50,&m100);
		n100=need/100;
		if(n100>=m100) n100=m100;
		need-=n100*100;
		n50=need/50;
		if(n50>=m50) n50=m50;
		need-=n50*50;
		n20=need/20;
		if(n20>=m20) n20=m20;
		need-=n20*20;
		n10=need/10;
		if(n10>=m10) n10=m10;
		need-=n10*10;
		n5=need/5;
		if(n5>=m5) n5=m5;
		need-=n5*5;
		n1=need;
		if(need<=m1) 
		{
			printf("%ld\n%ld %ld %ld %ld %ld %ld\n",n1+n5+n10+n20+n50+n100,n1,n5,n10,n20,n50,n100);
		}		else printf("poor BOSS Lei\n");
		
	} 
}
