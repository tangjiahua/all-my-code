#include<cstdio>
#include<stack>
#include<set>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<cmath>
using namespace std;
#define inf 0x3f3f3f3f
typedef long long ll;
const int N=110;
const int nmax = 23;
const double esp = 1e-9;
const double PI=3.1415926;
long long dp[nmax][nmax][2];
int vis[nmax],a[nmax];
void init(int n)
{
    memset(dp,0,sizeof(dp));
    dp[1][1][0]=1;  //初始条件
    dp[1][1][1]=1;
    for(int i=2; i<=n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            for(int k=j; k<i; k++)
            {
                dp[i][j][0]+=dp[i-1][k][1];
            } 
            for(int k=1; k<j; k++)
            {
                dp[i][j][1]+=dp[i-1][k][0];
            }
        }
    }
}
int main()
{
    int t;
    int n;
    ll id;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%lld",&n,&id);
        //n代表有多少木棍 id代表要求的第几套方案
        //a[]进去的是最后答案的顺序保存在数组中
        //sum
        //num
        //vis[]
        //ans
        memset(vis,0,sizeof(vis));
        memset(a,0,sizeof(a));
        init(n);
        ll sum=0;
        for(int i=1; i<=n; i++)
        {
            int num=0;
            for(int j=1; j<=n; j++)
            {
                if(vis[j])
                    continue;
                ll ans=0;
                ++num;
                if(i==1)
                {
                    ans=dp[n][num][0]+dp[n][num][1];
                }
                else
                {
                    if(j>a[i-1]&&(i==2||a[i-2]>a[i-1])){  //从第i个向前看是高低高……型
                        ans+=dp[n-i+1][num][1];
                    }
                    else if(j<a[i-1]&&(i==2||a[i-2]<a[i-1])){//从第i个向前看是低高高……型
                        ans+=dp[n-i+1][num][0];
                    }
                }
                sum+=ans;
                if(sum>=id)
                {
                    sum-=ans;
                    a[i]=j;
                    vis[j]=1;
                    break;
                }
            }
        }
        for(int i=1; i<n; i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n]);
    }
    return 0;
}