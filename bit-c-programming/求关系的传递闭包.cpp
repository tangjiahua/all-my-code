#include "stdio.h"
#include "math.h"
int main()
{
	int a[100];

	int n = 0;
	while(scanf("%d",&a[n]) != EOF)
		n++;
	n = (int)sqrt(n);

	int m[n][n], p = 0, mt[n][n];
	for(int k = 0; k < n; k++)
		for(int l = 0; l< n; l++)
		{
			mt[k][l] = a[p];
			m[k][l] = a[p++];
		}

	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
			{
				mt[i][j] = mt[i][j] || (mt[i][k] * mt[k][j]);
			}

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			printf("%d", mt[i][j]);
			if(j == n - 1) printf("\n");
			else printf(" ");
		}
	}
}
