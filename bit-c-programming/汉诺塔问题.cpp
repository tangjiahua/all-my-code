#include "stdio.h"
void movedisc( unsigned n,char from,char to,char need);
int i=0;
int main()
{
	unsigned n;
	while(scanf("%d",&n)!=EOF)
	{
		movedisc(n,'A','C','B');
		printf("Total steps: %d\n",i);

	}
}

void movedisc(unsigned n,char from,char to,char need)
{
	if(n==1)
	{
	printf("Move from %c to %c\n",from,to);
	++i;
	}
	else
	{
		movedisc(n-1,from,need,to);//第一，把a上的n-1个盘通过c移动到b
		printf("Move from %c to %c\n",from,to);//第二，把a上的最下面的盘移到c。
		movedisc(n-1,need,to,from);//第三，因为n-1个盘全在b上了，所以把b当做a重复以上步骤就好了。
		++i;
	}
}
