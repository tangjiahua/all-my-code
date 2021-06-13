#include "stdio.h"
#include "stdlib.h"
struct _d
{
    long long t;
    long long d;
}d[5005];
typedef struct _d NODE;
int cmp(const void *a, const void *b)
{
    NODE *x = (NODE*)a;
    NODE *y = (NODE*)b;
    return x->t - y->t;
}
int main(int argc, char const *argv[])
{
    int n, q;//n为人数 q为多少个k的取值
    scanf("%d %d", &n, &q);
    long di,ti;
    long long k, total = 0;
    for (int i = 0; i < n; i++)//存储进来
    {
        scanf("%ld %ld",&ti, &di);
        d[i].t = ti;
        d[i].d = di;
        total += di;
    }
    qsort(d, n, sizeof(NODE), cmp);
    for (int i = 0; i < n; i++)//合并同样的时间
    {
        for (int j = i+1; j < n; j++)
        {
            if(d[j].t == d[i].t)
            {
                d[i].d = d[i].d + d[j].d;
                d[j].t = 0;
                d[j].d = 0;
            }
        }
    }
    qsort(d, n, sizeof(NODE), cmp);
    for (int i = 0; i < q; i++)//开始对每一个k进行输出
    {
        long long start, end, max = 0, max1; //start开始结构下标，end为结束结构下标
        scanf("%lld", &k);
        if(k == 0)
        {
            printf("%lld\n", total);
            continue;
        }
        int m;//m是找到第一次统计时结束的下标
        for (int j = 0; j < n; j++)//j是找到第一个t不为0的下标
        {
            if(d[j].t != 0)
            {
                int flag = 0;
                start = j;
                max = max + d[j].d;
                for (m = j+1; m < n; m++)
                {
                    if(d[m].t >= d[start].t + k)
                    {
                        end = m - 1;
                        flag = 1;
                        break;
                    }
                    else
                    {
                        max = max + d[m].d;
                    }
                }
                if(flag == 1)
                    break;
                if(m == n)
                {
                    end = m;
                    break;
                }
            }
        }
        max1 = max;
        for(int j = end+1, m = start; j < n; j++)
        {
            
            max1 = max1 + d[j].d;//!!!
            while(d[m].t < d[j].t - k+1)
            {
                max1 = max1 - d[m].d;
                m++;
            }
            if(max1 > max)
                max = max1;
            if(m>j)
                m = j;
        }
        printf("%lld\n", total - max);
    }

    return 0;
}
