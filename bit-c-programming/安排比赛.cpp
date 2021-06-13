#include "stdio.h"
int main()
{
	int t;
	scanf("%d",&t);
	while(t){
		int n;
		scanf("%d",&n);
		if(n==1) printf("0\n");
		else {
			if(n%2==1) printf("%d\n",n);
			else printf("%d\n",n-1);
		}
		t--;
	}
} 
