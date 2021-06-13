#include "stdio.h"
int main()
{
	int list,i,j,t;
	char judge[51];
	scanf("%d",&list);
	getchar();
	for(i=0;i<list;i++)
	{
		t=0;
		gets(judge);
		if(judge[0]=='_'||(judge[0]>='a'&&judge[0]<='z')||(judge[0]>='A'&&judge[0]<='Z')) ;
			else 
			{
				printf("no\n");
				continue;
			}
		for(j=1;judge[j]!='\0';j++)
		{
			if(judge[j]=='_'||(judge[j]>='a'&&judge[j]<='z')||(judge[j]>='A'&&judge[j]<='Z')||(judge[j]>='0'&&judge[j]<='9'))
			continue;
			else
				{
					t=printf("no\n");
					break;
				}
			
		}
		if(t==0) printf("yes\n");	
	}
}

