#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define AC 1;
int m, n, k, f,zuo,you,flag_0,pp,clock;
int number[10005];
char mstack[10005];

void myfunc(char ch)
{
	int p = 0;

	switch (ch)
	{
		case '+':
			p = number[n - 2] + number[n - 1];
			break;
		case '-':
			p = number[n - 2] - number[n - 1];
			break;
		
		case '*':
			p = number[n - 2] * number[n - 1];
			break;
		case '/':
			if (number[n - 1] == 0)
			{
				flag_0 = 1;
				return;
			}
			else
			{
				p = number[n - 2] / number[n - 1];
				break;
			}
		case '^':
			if (number[n - 1] < 0)
			{
				clock = 1;
				return;
			}
			else
			{
				p = pow(number[n - 2], number[n - 1]);
				break;
			}
		case '%':
			p = number[n - 2] % number[n - 1];
			break;
	}
	n -= 2;
	number[n++] = p;
}


void calculate()
{
	char ch = getchar();
	while (ch != '\n')
	{
		
		if (ch == '(')
		{
			mstack[m++] = ch;
			zuo++;
			ch = getchar();
		}
		if (ch >= '0' && ch <= '9')
		{
			f = 0;
			while (ch >= '0' && ch <= '9')
			{
				if (pp != 1)
				{
					if (f == 0)
					{
						number[n] = ch - '0';
						f = 1;
					}
					else
					{
						number[n] = number[n] * 10 + ch - '0';
					}
					
				}
				else
				{
					if (f == 0)
					{
						number[n] = '0' - ch;
						f = 1;
					}
					else
					{
						number[n] = number[n] * 10 - ch + '0';
					}
				}
				ch = getchar();
				if (ch == '(')
				{
					clock = 1;
				}
			}
			n++;
			k = 0;
			pp = 0;
		}
		else if (ch == '+' || ch == '-')
		{
			if (k != 1)
			{
				if (!m)
					mstack[m++] = ch;
				else
				{
					if (mstack[m - 1] == '(')
						mstack[m++] = ch;
					else
					{
						while (m)
						{
							if (mstack[m - 1] == '+' || mstack[m - 1] == '-' || mstack[m - 1] == '*' || mstack[m - 1] == '/' || mstack[m - 1] == '%' || mstack[m - 1] == '^')
								myfunc(mstack[--m]);
							else
								break;
						}
						mstack[m++] = ch;
					}
				}
				k = 1;
				ch = getchar();
			}
			else
			{
				pp = 1;
				ch = getchar();
				continue;
			}
		}
		else if (ch == '*' || ch == '/' || ch == '%')
		{
			if (!m)
				mstack[m++] = ch;
			else
			{
				if (mstack[m - 1] == '(')
					mstack[m++] = ch;
				else
				{
					while (m)
					{
						if (mstack[m - 1] == '*' || mstack[m - 1] == '%' || mstack[m - 1] == '/' || mstack[m - 1] == '^')
							myfunc(mstack[--m]);
						else
							break;
					}
					mstack[m++] = ch;
				}
			}
			k = 1;
			ch = getchar();
		}
		else if (ch == ')')
		{
			you++;
			while (m)
			{
				if (mstack[m - 1] == '(')
				{
					m--;
					break;
				}
				else
					myfunc(mstack[--m]);
			}
			ch = getchar();
			if (ch == '(' || (ch >= '0' && ch <= '9'))
				clock = 1;
			
		}
		else if (ch == '^')
		{
			mstack[m++] = ch;
			k = 1;
			ch = getchar();
		}
	}
}


int main()
{
	int N;
	scanf("%d", &N);
	getchar();

	while (N--)
	{
		//初始化阶段
		zuo = 0;
		you = 0;
		flag_0 = 0;
		clock = 0;
		pp = 0;
		m = 0;
		n = 0;
		f = 0;
		k = 1;
		memset(number, 0, sizeof(number));
		memset(mstack, 0, sizeof(mstack));

		calculate();

		while (m)
		{
			if (mstack[m - 1] == '+' || mstack[m - 1] == '-' || mstack[m - 1] == '*' || mstack[m - 1] == '^' || mstack[m - 1] == '/' || mstack[m - 1] == '%' )
				myfunc(mstack[m - 1]);
			m--;
		}
		
		if (zuo != you || clock == 1)
			printf("error.\n");
		else if (flag_0)
			printf("Divide 0.\n");
		else
			printf("%d\n", number[0]);
	}
	return AC;
}


