#include "stdio.h"
long long f[2005][2];
int main(int argc, char const *argv[])
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n, m, k;
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 0; i <= n + 1; i++){
            f[i][0] = 0;
            f[i][1] = 0;
        }
        f[1][0] = 1;
        if(k == 1){
            f[1][1] = m;
        }
        else {
            f[1][1] = 0;
            f[k][1] = m;
        }
        for (int i = 2; i <= n; i++){
            if(i == k){
                f[i][0] = (f[i - 1][0]%998244353 + f[i - 1][1]%998244353)%998244353; 
                f[k][1] = m;
                continue;
            }
            else{
                f[i][0] = (f[i - 1][0]%998244353 + f[i - 1][1]%998244353)%998244353; 
                if(i < k){
                    f[i][1] = f[i - 1][1]%998244353;
                }
                else{
                    f[i][1] = (f[i - 1][1]%998244353+f[i - k][0]%998244353 * m+f[i - k][1]%998244353 * (m - 1))%998244353;
                }
            }
        }
        printf("%lld\n", (f[n][0]%998244353+f[n][1]%998244353)%998244353);
    }
    return 0;
}
