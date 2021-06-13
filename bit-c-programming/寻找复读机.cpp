#include "string.h"
#include "stdio.h"
int main(int argc, char const *argv[])
{
    int n, m, flag = 0, count = 0;
    char ch[110], ch1[110],ch2[110];
    for(int i = 0; i < 110; i++)
    {
        ch1[i] = '\0';
        ch2[i] = '\0';
        ch[i] = '\0';
    }

    scanf("%d %d", &n, &m);
    int fuduji[n][2], x;
    for (int i = 0; i < n; i++)
    {
        fuduji[i][1] = '1';
    }
    
    
    while (flag < m)
    {
        scanf("%d %s", &x, &ch);
        if(strcmp(ch, ch1) != 0) //与上一个人说的东西不同
        {
            fuduji[x - 1][1] = '0';
            
            strcpy(ch1, ch2);
            strcpy(ch1, ch);
        }
        flag++;
    }

    for (int i = 0; i < n; i++)
    {
        if(fuduji[i][1] != '0')
        {
            count = 1;
            break;
        }
    }

    if(count == 0)
    {
        ;
    }
    else
    {
        int flag2 = 0;
        for (int i = 0; i < n; i++)
        {
            if(fuduji[i][1] == '1' && flag2 == 0)
            {
                printf("%d", i + 1);
                flag2 = 1;
            }
            else if(fuduji[i][1] == '1' && flag2 == 1)
            {
                 printf(" %d", i + 1);
            }
            else
                ;
        }
        printf("\n");   
    }



    return 0;
}
