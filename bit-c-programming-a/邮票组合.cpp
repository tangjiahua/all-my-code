#include "stdio.h"
int main()
{
	int a,b,c,d;
	int left,answer,i1,i2,i3,i4;
	while(scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF)
	{
		answer=0;
		left=0;
	fuck:for(i1=0;i1<=5;i1++)
			for(i2=0;i2<=5;i2++)
				for(i3=0;i3<=5;i3++)
					for(i4=0;i4<=5;i4++)
					{
						if((d*i1+c*i2+b*i3+a*i4==left)&&(i1+i2+i3+i4<=5)) answer++; 
					}
		if(answer!=0){
			answer=0;
			left++;
			goto fuck;
		}
		printf("The max is %d.\n",left-1);
	} 
}
