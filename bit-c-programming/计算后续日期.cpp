#include "stdio.h"
int main()
{
	int y,m,d,n,i;
	while(scanf("%d %d %d",&y,&m,&d)!=EOF)
	{
		scanf("%d",&n);
		int d2=d;
		while(n>0)
		{
			int dmax,m2;
			if(m==1||m==3||m==5||m==7||m==8||m==10||m==12) dmax=31;	/*dmax mou yue zui duo tian shu*/
			if(m==4||m==6||m==9||m==11) dmax=30;
			if(m==2) 
			{
				if(y%4==0&&y%100!=0||y%400==0) dmax=29;
				else dmax=28;
			}
			
			if(d2+n>dmax)
			{
				m++;
				n-=(dmax-d2);
				d2=0;
			}
			else
			{
				d2=d2+n;
				break;
			}
			if(m==13)
			{
				m=1;
				y++;
			}
			
		}
		printf("%d.%d.%d\n",y,m,d2);
	}
}
