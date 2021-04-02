#include "stdio.h"
int main()
{
	char ch[100],way;
	int max,min,i,ans,j;
	while(gets(ch)!=NULL)
	{
		i=0,j=0;
		while(ch[i]!='=')
		{
			
			if(i==0) min=max=ch[i]-48;
			if(ch[i]==',') {i++; continue;
			}
			if(ch[i]>='0'&&ch[i]<='9')
			{
				if(min>ch[i]-48) min=ch[i]-48;
				if(max<ch[i]-48) max=ch[i]-48;
			}
			else way=ch[i];
			i++;
		}
		
		switch(way)
		{
			case '+': {ans= max + min;
				break;
			}
			case '-': {ans= max-min;
				break;
			}
			case '*': {ans= max*min;
				break;
			}
			case '/': {
				if(min==0) {printf("Error!\n");j=1;
				}
				else ans= max/min;
				break;
			}
			case '%': if(min==0){printf("Error!\n");j=1;
				}
				else ans=max%min;
				break;
			}
			if(j!=1) printf("%d%c%d=%d\n",max,way,min,ans);
		else continue;
		}
		

	}

