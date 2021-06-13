#include "stdio.h"
int main(int argc, char const *argv[])
{
	char seat[5][12];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 12; j++)
			seat[i][j] = '#';
	for(int i = 1; i < 12; i++)
		seat[2][i] = '.';

	int k;
	scanf("%d",&k);
	if(k == 49) printf("no\n");
	else
	{
		if(k <= 44 && k > 0)
		{
			int n = k, i = 0, j = 11, p = 0;
			do
			{
				p++;
				seat[i++][j] = 'O';
				if(i == 2) i++;
				if(i == 5) i = 0;
				if(p == 4)
				{
					p = 0;
					j--;
				}
				n--;
			}while(n > 0);
		}

		if(k > 44)
		{
			int n = k - 44, i = 0, j = 1;
			do
			{
				seat[i][j] = 'O';
				j++;
				if(j == 12)
				{
					i++;
					j = 1;
				}
				if(i == 2)
				{
					i++;
				}
			}while(i < 5);

			int p = 0;
			do
			{
				seat[p++][0] = 'O';
				n--;
			}while(n > 0);
		}

		int m = 0;
		for(int i = 11; i > -1; i--)
		{
			for(int j = 0; j >= 0; j++)
			{
				if(j == 5)
				{
					j = 0;
					break;
				}
				if(seat[j][i] == '#')
				{
					seat[j][i] = 'X';
					m = 1;
					break;
				}
			}
			if(m == 1) break;
		}




		printf("yes\n");
		printf("+--------------------------+\n");
		for(int i = 0; i < 5; i++)
		{
			putchar('|');
			for(int j = 0; j < 12; j++)
			{
				putchar(seat[i][j]);
				putchar('.');
				if(j == 11 && i == 0 )
				{
					printf("|D|)\n");
				}
				else if(j == 11 && (i == 1 || i == 3 ))
					printf("|.|\n");
				else if(j == 11 && i == 4)
				{
					printf("|.|)\n");	
				}
				else if(j == 11 && i == 2 )
				printf("..|\n");
			}
		}
		printf("+--------------------------+\n");
	}

	return 0;
}
