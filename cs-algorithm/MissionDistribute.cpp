#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
#define Min 0x7fffffff
int n;
bool miassions[15];
int minimis;
int worrkerrs[15][15];

int miN[14];//每

void func(int kk,int curren_time)//
{
	int minimisum; int j;
	if (kk >= n+1){//
		minimis = min(minimis, curren_time);
		return; }
	if (curren_time > minimis) return;//
	for (int i = 1; i<=n; i++)//枚
	{
		if (miassions[i] == 0)
		{
			//
			for (minimisum = curren_time + worrkerrs[kk][i], j = 1; j <= n; j++)
			{
				if (!miassions[j] && j != i)
					minimisum += miN[j];
			}
			if (minimisum < minimis)
			{
				miassions[i] = true;//表示
				func(kk + 1, curren_time + worrkerrs[kk][i]);
				miassions[i] = false;//去掉
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{ 
		miN[i] = Min;
	    for (int j = 1; j <= n; j++)
		cin >> worrkerrs[i][j];
	}

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	if (worrkerrs[i][j] < miN[j])
		miN[j] = worrkerrs[i][j]; //找 

	minimis = Min;
	func(1,0);
	cout << minimis<<endl;
	return 0;
}
