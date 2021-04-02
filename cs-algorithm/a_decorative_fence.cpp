#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 25
#define INF 0x3fffffff
using namespace std;
int out[N];
long long ddpp[N][N][2],m;
int usinged[N];
int n,T;
void solving(){
    int i,j,k;
    ddpp[1][1][0] = ddpp[1][1][1] = 1;
    memset(ddpp, 0, sizeof(ddpp));
    ddpp[1][1][0] = ddpp[1][1][1] = 1;
    for(i = 2;i<=n;i++){
        for(j = 1;j<=i;j++){
            for(k = 1;k<=j-1;k++)
                ddpp[i][j][1] += ddpp[i-1][k][0];
            for(k = j;k<=i-1;k++)
                ddpp[i][j][0] += ddpp[i-1][k][1];
        }
    }
}
int iddmm(int i){
    int j,sumofall;
    for(j = 1,sumofall=0;j<=n;j++){
        if(!usinged[j])
            sumofall++;
        if(sumofall == i)
            return j;
    }
    return -1;
}
void print_func(long long y){
    int i,j,k,x,start,last,shang,xia;
    memset(usinged, 0, sizeof(usinged));
    last = x = n;
    start = 1;
    shang = xia = 1;
    for(i = 1;i<=n;i++){
        for(j = start;j<=last;j++){
            if(xia && y <= ddpp[x][j][1]){//如果采用的是第j小数开头的xia方案
                k = iddmm(j);//取得第j小数
                out[i] = k;
                usinged[k] = 1;
                start = 1;//那么下一个数只能是up方案，而且起始数字只能是从第1小到第i-1小（即比这个位置选出的数字小）
                last = j-1;
                xia = 0;//表示下一个数只能是up方案
                shang = 1;
                
                break;
            }
            if(xia && y>ddpp[x][j][1])//注意逻辑清晰
                y -= ddpp[x][j][1];
            if(shang && y<= ddpp[x][j][0]){
                k = iddmm(j);
                out[i] = k;
                usinged[k] = 1;
                start = j;//与上面同理，下一个只能是down方案，而且只能是以第j小到第x-1小打头
                last = x-1;
                shang = 0;
                xia = 1;
                break;
            }
            if(shang && y>ddpp[x][j][0])
                y = y-  ddpp[x][j][0];
        }
        x = x -1;
    }
    for(int pp = 1;pp<n;pp++)
        printf("%d ",out[pp]);


    printf("%d\n",out[n]);
}
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d %lld",&n,&m);
        solving();
        print_func(m);
    }
    return 0;
}
