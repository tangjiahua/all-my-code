#include "stdio.h"
struct biao
{
        char ch;
        int p;
};
int main()
{
    struct biao a[62];
    for(int i = 0; i < 62; i++)
    {
    	a[i].p = 0;
    }

    long long n;
    char ch1;
    scanf("%lld\n", &n);
    while(n-->0)//统计字符出现的次数
    {
        ch1 = getchar();

        for (int i = 0; i < 62; i++)
        {
            if(a[i].p == 0)
            {
                a[i].ch = ch1;
                a[i].p++;
                break;
            }
            else if(a[i].p != 0 && a[i].ch == ch1)
            {
                a[i].p++;
                break;
            }
            else
                continue;
        }
    }

    //统计偶数组数和奇数组数
    long long ji = 0;
    for (int i = 0; i<62; i++)
    {
        if((a[i].p %2) == 1) ji++;
    }

    //开始输出

        if(ji == 0)
            printf("0\n");
        else 
            printf("%lld\n", ji - 1);
        for (int i = 0; i < 62; i++) //输出左边
        {
            if ((a[i].p%2) == 0)
            {
                for (int j = 0; j < (a[i].p / 2); j++)
                {
                    putchar(a[i].ch);
                    
                }
            }
        }
        for (int i = 0; i < 62; i++) //输出左zhongjian
        {
            if ((a[i].p%2) == 1)
            {
                for (int j = 0; j < a[i].p; j++)
                {
                    putchar(a[i].ch);
                    
                }
                a[i].p = 0;
                break;
            }
        }
        for (int i = 61; i >= 0; i--) //输出右边
        {
            if ((a[i].p)%2 == 0)
            {
                for (int j = 0; j < (a[i].p / 2); j++)
                {
                    putchar(a[i].ch);
                    
                }
            }
        }
        printf("\n");
        for (int i = 0; i <62; i++) //输出ji
        {
            if ((a[i].p%2) == 1)
            {
                for (int j = 0; j < a[i].p; j++)
                {
                    putchar(a[i].ch);
                    
                }
                printf("\n");
            }

        }

    
    return 0;
}
