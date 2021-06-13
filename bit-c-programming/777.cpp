#include<stdio.h>
#include<string.h>
#include<math.h>

#define mod 100000000
#define maxn 20010
#define last 4000

char r_str[maxn], l_str[maxn];
int r[maxn], l[maxn];
int my_one[maxn];

void add(int *temp, int x)//实现加运算
{
	temp[last] += x;
	for (int i = last; i >= 0; i--)
	{
		if (temp[i] < mod)
		{
			break;
		}
		temp[i - 1] += temp[i] / mod;
		temp[i] %= mod;
	}

}

void sub(int *temp, int *x)//实现减运算
{
	for (int i = last; i >= 0; i--)
	{
		temp[i] -= x[i];
	}

	for (int i = last; i > 0; i--)
	{
		if (temp[i] < 0)
		{
			temp[i - 1]--;
			temp[i] += mod;
		}
	}

}
void mul(int *a, int x)//实现乘运算
{
	int first = 0;

	for (; a[first] == 0; first++);

	for (int i = last; i >= first; i--)
	{
		a[i] *= x;
	}

	for (int i = last; i >= first - 1; i--)
	{
		a[i - 1] += a[i] / mod;
		a[i] %= mod;
	}
}

void get(char *a, int *cnt)
{
	int temp1[maxn], temp2[maxn];
	int	change[maxn];

	memset(temp1, 0, sizeof(temp1));
	memset(temp2, 0, sizeof(temp2));

	int len = strlen(a);
	int flag = 0;

	if (strcmp(a, "7") == 0)
	{
		cnt[last] = 1;
		return;
	}

	for (int i = 0; i < len; i++)
	{
		change[i] = a[i] - '0';
	}

	temp1[last] = change[0];
	temp2[last] = change[0];

	if (change[0] > 7)
		temp2[last]--;

	if (change[0] == 7)
		flag = 1;

	for (int i = 1; i < len; i++)
	{

		mul(temp1, 10); 
		mul(temp2, 9);

		add(temp1, change[i]);

		if (flag == 0)
		{
			add(temp2, change[i]);
			if (change[i] > 7)
				sub(temp2, my_one);
		}
		if (change[i] == 7)
		{
			flag = 1;
		}
	}
	sub(temp1, temp2);

	if (flag && len > 1)
	{
		add(temp1, 1);
	}
	for (int i = 0; i <= last; i++)
	{
		cnt[i] = temp1[i];
	}

}

void solve()
{
	my_one[last] = 1;
	memset(l_str, 0, sizeof(l_str));
	memset(r_str, 0, sizeof(r_str));
	memset(r, 0, sizeof(r));
	memset(l, 0, sizeof(l));
    scanf("%s %s", l_str, r_str);
	get(l_str, l);//算出1-lift有多少个7
	get(r_str, r);//算出1-right有多少个7
	sub(r, l);
	for (int i = 0; l_str[i]; i++)//把左边界的情况也算上
	{
		if (l_str[i] == '7')
		{
			add(r, 1);
			break;
		}
	}
}

void my_print()
{
	int pos = 0;
	for (; r[pos] == 0 && pos <= last; pos++);

	printf("%d", r[pos++]);
	for (; pos <= last; pos++)
	{
		printf("%08d", r[pos]);
		//在printf中%08d表示输出宽度为8，不足8位的补0，%8d表示输出宽度为8，不足8位的补空格
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		solve();
		my_print();
	}
	return 0;
}