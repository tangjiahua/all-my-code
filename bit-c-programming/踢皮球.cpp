#include "stdio.h"
int a[105], b[105];
int n = 0;
int yuetan(int yue, int guo, int shuchu)
{
    if(b[guo] == 1 && shuchu != n-1)
    {
        printf("%d ",guo+1);
        return 0;
    }
    if(b[guo] == 1 && shuchu == n-1)
    {
        printf("%d\n", guo+1);
        return 0;
    }
    if(b[guo] == 0)
    {
        b[guo] = 1;
        yuetan(guo, a[guo]-1, shuchu);
        return 0;
    }
}

int main()
{
    
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            b[j] = 0;
        b[i] = 1;
        yuetan(i, a[i]-1, i);
    }
    return 0;
}