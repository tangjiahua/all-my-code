#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct node
{
    long long price,number,id;
}x[10005];

int main()
{
   long long n,m;
   scanf("%lld%lld",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%lld%lld",&x[i].price,&x[i].number),x[i].id=i;
    long long ans=x[0].price*x[0].number,k=0,now,before;
    for(int i=1;i<n;i++)
    {
        now=x[i].price*x[i].number;
        before=(x[k].price+m*(i-k))*x[i].number;
        if(now>before)
            ans+=before;
        else
        {
            ans+=now;
            k=i;
        }
    }
    printf("%lld\n",ans);
   return 0;
}