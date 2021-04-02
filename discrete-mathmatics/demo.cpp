#include <stdio.h>
int main()
{
    int n, g[105][105], flagx;
    int i, j, k;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &g[i][j]);
        }
        g[i][i] = 1;
    }
    for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				g[i][j]=g[i][j]||(g[i][k]&&g[k][j]);       

    flagx = 1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (g[i][j] + g[j][i] == 1) //存在单向联通的点
                flagx = 2;
            if (g[i][j] == 0 && g[j][i] == 0)
            {
                printf("3\n");
                return 0;
            }
        }
    }
    printf("%d\n", flagx);
}
