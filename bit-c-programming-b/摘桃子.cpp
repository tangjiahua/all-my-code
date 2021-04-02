#include "stdio.h"
int main(int argc, char const *argv[])
{
	int n, v;
	scanf("%d %d",&n, &v);
	int a[n], b[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d %d",&a[i], &b[i]);
	}

	int max = a[0];
	for(int i = 0; i < n; i++)
		if(a[i] > max) max = a[i];

	int c[max+1];
	for(int i = 0; i < max+1; i++)
		c[i] = 0;

	for(int i = 0; i < max; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(a[j] == i+1)
			{
				c[i] = c[i] + b[j];
			}
		}
	}

	int result = 0;

	for(int i = 0; i < max+1; i++)
	{
		if(i == 0)
		{
			if(v <= c[i])
			{
				c[i] = c[i] - v;
				result += v;
				continue;
			}
			else
			{
				result += c[i];
				c[i] = 0;
				continue;
			}
		}

		if(v <= c[i-1])
		{
			c[i-1] = c[i-1] - v;
			result += v;
			continue;
		}

		else
		{
			result += c[i-1];
			int x = v - c[i-1];
			c[i-1] = 0;
			if(x <= c[i])
			{
				c[i] = c[i] - x;
				result += x;
				continue;
			}
			else
			{
				result += c[i];
				c[i] = 0;
				continue;
			}
		}
	}

	printf("%d\n",result);
	return 0;
}
