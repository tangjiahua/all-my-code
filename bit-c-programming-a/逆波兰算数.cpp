#include "stdio.h"
#include "string.h"
int main()
{
	char ch[1000];
	int temp[1000] = {0}, i = 0;
	int d, j = 0,x = 0;
	gets(ch);
	d = strlen(ch);
	while(j<d)
	{
		if(ch[j]>='0'&&ch[j]<='9')
		{
			temp[x] = ch[j]-48;
			i = j+1;
			while(ch[i]>='0'&&ch[i]<='9')
			{
				temp[x] = temp[x]*10 + ch[i] - 48;
				i++;
			}
			j = i;
			x++;
		}
		
		else if(ch[j] > 41 && ch[j] < 48)
		{
			switch(ch[j])
			{
				case '+': temp[x-2] = temp[x-2]+temp[x-1];temp[--x] = 0;j++;break;
				case '-': temp[x-2] = temp[x-2]-temp[x-1];temp[--x] = 0;j++;break;
				case '*': temp[x-2] = temp[x-2]*temp[x-1];temp[--x] = 0;j++;break;
				case '/': temp[x-2] = temp[x-2]/temp[x-1];temp[--x] = 0;j++;break;
			}
		}
		else{
			j++;
			continue;
		};
	}
	printf("%d\n",temp[0]);
}
