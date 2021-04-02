#include <bits/stdc++.h>
#include <stdio.h>
using namespace std; 
const int N=500010; 
const int INF=0x3f3f3f3f;
long long n;
long long dp[3][N], a[N];
long long cmp(long long x, long long y){
	if(x > y) return x;
	else return y;
}
int main()  
{
    scanf("%lld", &n);
    for(int i=1;i<=n;i++) 
        scanf("%lld",&a[i]);
    for(int i=0;i<=n;i++)
			dp[0][i]=0,dp[1][i]=0;   
		
    for(int i=1;i<=3;i++)
    {
        long long maxpre = -INF; 
        for(int j=i;j<=n;j++)
        {
            if(j == i){
                dp[i][j] = dp[i - 1][j - 1] + a[j];
                continue;
            }
            maxpre=cmp(maxpre,dp[i-1][j-1]);  
            dp[i][j]=cmp(dp[i][j-1],maxpre)+a[j];
        }
    }
    long long max = dp[3][3];
    for(int i = 4; i <= n; i++){
        if(dp[3][i] > max)
            max = dp[3][i];
    }
    printf("%lld\n",max);
}
