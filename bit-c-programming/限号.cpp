#include <stdio.h>
int father[1000][105];
int m;
//查找函数
int Find(int x, int y)
{
	while(father[x][y]!=x)
		x=father[x][y];
 
	return x;
}
//合并函数
void combine(int a,int b, int c)
{
    int temp_a,temp_b;
	temp_a=Find(a, c);
	temp_b=Find(b, c);
    
	if(temp_a!=temp_b)
		father[temp_a][c]=temp_b;
}
//确定连通分量个数
int find_ans(int u, int v)
{
    int ans = 0;
    for (int i = 1; i <= m; i++){
        if(Find(u, i) == Find(v, i)){
            ans++;
        }
    }
    return ans;
}
 
int main()
{
    int n, a, b, c, k, u, v;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            father[i][j] = i;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        combine(a, b, c);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++){
        scanf("%d%d", &u, &v);
        printf("%d\n", find_ans(u, v));
    }
        /*
	while(scanf("%d",&n)!=EOF)
	{
	    if(!n)  break;
		Init(n);
		scanf("%d",&m);
 
		for(i=0;i<m;++i)
		{
			scanf("%d%d",&a,&b);
			combine(a,b);
		}
		printf("%d\n",find_ans(n)-1);
	}
    */
        return 0;
}
 
