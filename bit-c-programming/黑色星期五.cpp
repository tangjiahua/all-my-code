#include "stdio.h"
int main()
{
	int y,m,d,count,j,w,yy;
	int put[8];
	while(scanf("%d",&y)!=EOF)
	{
		yy=y;
		j=0;
		count=0;
		for(m=1;m<12;m++)
		{
			if(m==1) {m=13;y=y-1;}
			if(m==2) {m=14;y=y-1;}
			w=(13+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
			if(w==4)
			{
				count++;
				if(m==13) {
				put[j]=1;m=1;j++;}
				else if(m==14) {
				put[j]=2;m=2;j++;}
				else {
					put[j]=m;
					j++;
				}
				
			}
			if(m==13) m=1;
			if(m==14) m=2;
			y=yy;
		}
		if(count==1)
		{
			printf("There is %d Black Friday in year %d.\nIt is:\n",count,y);
			for(j=0;j<count;j++)
				printf("%d/%d/13\n",yy,put[j]);
			continue;
		}
		printf("There are %d Black Fridays in year %d.\nThey are:\n",count,y);
		for(j=0;j<count;j++)
			printf("%d/%d/13\n",yy,put[j]);
	}
} 
