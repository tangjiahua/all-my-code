#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<math.h>
using namespace std;
#ifndef Kuo_Zhan  
#define Kuo_Zhan  
 
#pragma comment(linker, "/STACK:268435456,268435456")  
 
#endif // Kuo_Zhan  
vector<int> son[200005];
long long a[200005];
long long dp[200005][2];

void dfs(int x)
{
	int len = son[x].size();
	if (len == 0)
	{
		dp[x][1] = a[x];
		return;
	}
	dp[x][1] = -8223372036854775807;

	for(int i = 0; i < len; i++)
	{
		long long ans = son[x][i];
		dfs(ans);
	    long long x1 = dp[x][0];
		long long x2 = dp[x][1];
		dp[x][1] = max(x2 + dp[ans][0], x1 + dp[ans][1]);
		dp[x][0] = max(x1 + dp[ans][0], x2 + dp[ans][1]);
	}

	dp[x][1] = max(dp[x][0] + a[x], dp[x][1]);
	return;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		long long x, y;
		scanf("%lld %lld", &x, &y);
		a[i] = y;
		if (x != -1)	son[x].push_back(i);
	}
	dfs(1);
	printf("%lld\n", dp[1][1]);
	return 0;
}