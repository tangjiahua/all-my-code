#include "stdio.h"
long long p;
long long dp[4005];
int main()
{
    int n, v;
    dp[0] = 1;
    scanf("%d%d", &n, &v);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &p);
        p = p % v;
        if(p == 0)
            p = v;

        for (int j = 2 * v; j >= p; j--){
            dp[j] = (dp[j] + dp[j - p])%10000000;
        }

        for (int j = 2 * v; j >= p; j--){
            if(j > v){
                dp[j - v] =(dp[j-v] + dp[j])%10000000;
                dp[j] = 0;
            }
        }
    }
    printf("%lld\n", dp[v]%10000000);

    return 0;
}