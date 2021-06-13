#include "stdio.h"
int main()
{
	int y,m,d,c=0,q,m2,i=1900,run=0;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF)
	{
		m2=28;
		run=0;
		if(m>12)
		{
			printf("month is error.\n");
			continue;
		}
		if(d>31)
		{
			printf("day is error.\n");
			continue;
		}
		while(i<y)
		{
			if(((i%4)==0&&(i%100)!=0)||((y%400)==0)) run++;
			i++;
		}
		c=366*run+365*(y-1900-run);
		if(((y%4)==0&&(y%100)!=0)||((y%400)==0)) m2=29;
		switch(m)
		{
			case 1: c=c; break;
			case 2: c=c+31; break;
			case 3: c=c+31+m2; break;
			case 4: c=c+31+m2+31; break;
			case 5: c=c+31+m2+31+30; break;
			case 6: c=c+31+m2+31+30+31; break;
			case 7: c=c+31+m2+31+30+31+30; break;
			case 8: c=c+31+m2+31+30+31+30+31; break;
			case 9: c=c+31+m2+31+30+31+30+31+31; break;
			case 10: c=c+31+m2+31+30+31+30+31+31+30; break;
			case 11: c=c+31+m2+31+30+31+30+31+31+30+31; break;
			case 12: c=c+31+m2+31+30+31+30+31+31+30+31+30; break;
			
		}
		c=c+d-1;
		q=c%7+1;
		if(q==7) q=0;
		printf("%d\n",q);
	}
} 
