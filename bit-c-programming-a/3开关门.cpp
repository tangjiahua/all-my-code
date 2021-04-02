#include "stdio.h"
#include "string.h" 
int main()
{
	int days,d,list,i,h1,m1,s1,h2,m2,s2;
	long num1[99],num2[99],max,min;
	char id[20],close[20],open[20];
	scanf("%d",&days);
	for(d=0;d<days;d++)
	{
		scanf("%d",&list);
		for(i=0;i<list;i++)
		{
			if(i==0)
			{
				max=0;min=999999;
			}
			scanf("%s %d:%d:%d %d:%d:%d",&id,&h1,&m1,&s1,&h2,&m2,&s2);
			num1[i]=h1*10000+m1*100+s1;
			num2[i]=h2*10000+m2*100+s2;
			if(num1[i]<min) 
			{
			strcpy(open,id);
			min=num1[i];}
			if(num2[i]>max)
			{
			strcpy(close,id);
			max=num2[i];}
		}
		printf("%s %s\n",open,close);
		
	}
}
