#include "stdio.h"
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int i;
		for(i=0;i<n;i++)
			{
				int y,m,d,all=0;
				scanf("%d%d%d",&y,&m,&d);
				int y2;
				int run=0,month=28;
				for(y2=1990;y2<y;y2++)
				{
					if((y2%4==0)&&(y2%100!=0)||y2%400==0)
					{
						all+=366;
					}
					else 
					{
						all+=365;
				
					}
				}
				
				if(m==1)
				{
					all+=d;
				}
				else if(m==2)
				{
					all+=d+31;
				}
				else if(m>2)
				{
					if((y2%4==0)&&(y2%100!=0)||y2%400==0) month=29;
					switch(m)
					{
						case 3: all+=31+month+d;break;
						case 4:	all+=31*2+month+d;break;
						case 5: all+=31*2+month+d+30;break;
						case 6: all+=31*3+month+d+30*1;break;
						case 7: all+=31*3+month+d+30*2;break;
						case 8: all+=31*4+month+d+30*2;break;
						case 9: all+=31*5+month+d+30*2;break;
						case 10: all+=31*5+month+d+30*3;break;
						case 11: all+=31*6+month+d+30*3;break;
						case 12: all+=31*6+month+d+30*4;break;
					}
				}
				
				all=(all-1)%5;
				if(all>=0&&all<=2) printf("He was fishing on %d.%d.%d\n",y,m,d);
				else printf("He was basking on %d.%d.%d\n",y,m,d);
	}
}}
