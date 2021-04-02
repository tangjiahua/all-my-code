/*n:持有 m:需要*/ 
#include<stdio.h>
int main()
{
	int m,n1,n5,n10,n20,n50,n100,m1,m5,m10,m20,m50,m100;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d %d %d %d %d %d %d",&m,&n1,&n5,&n10,&n20,&n50,&n100);
		m100=m/100;
		if(m100>n100) m100=n100;
		m-=(100*m100);
		m50=m/50;
		if(m50>n50) m50=n50;
		m-=(50*m50);
		m20=m/20;
		if(m20>n20) m20=n20;
		m-=(20*m20);
		m10=m/10;
		if(m10>n10) m10=n10;
		m-=(10*m10);
		m5=m/5;
		if(m5>n5) m5=n5;
		m-=(5*m5);
		m1=m;
		if(m1<=n1)
		   printf("%d\n%d %d %d %d %d %d\n",m1+m5+m10+m20+m50+m100,m1,m5,m10,m20,m50,m100);
		else
		printf("poor BOSS Lei\n"); 
	}
}

