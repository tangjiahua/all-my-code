#include "string.h"
#include "stdio.h"
#include "math.h"
int main(int argc, char const *argv[])
{
    unsigned char ch, ch1, ch2;
    int t, tt, ttt, m, x, xx, xxx;
    long zi[65536];
    memset(zi, 0, sizeof(zi));

    while(scanf("%c", &ch) != EOF)//
    {
        t = ch;
        if(t < 128)
            ;
        else if(t<224 && t>=192)
        {
            ch1 = getchar();
            tt = ch1;
            m = (t - pow(2, 7) - pow(2, 6)) * pow(2, 6) + tt - pow(2, 7);

            zi[m]++;
        }
        else
        {
            ch1 = getchar();
            ch2 = getchar();
            tt = ch1;
            ttt = ch2;
            m = (t - pow(2, 7) - pow(2, 6) - pow(2, 5)) * pow(2, 12) + (tt - pow(2, 7)) * pow(2, 6) + ttt - pow(2, 7);
            zi[m]++;
        }
            
    }

    int flag = 0;
    for (int i = 0; i < 65536; i++)
    {
        if(zi[i] > 1)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 1)
    {
        for (int i = 128; i < 65536; i++)
        {
            if(i >= 128 && i < 2048)
            {
                if(zi[i] > 1)
                {
                    x = i/64 + 192;
                    xx = i%64+128;
                    printf("%c%c 0x%04x %ld\n", x, xx, i, zi[i]);//注意汉字的输出方式
                }
            }

            
            else
            {
                if(zi[i] > 1)
                {
                    xxx = i % 64 + 128;
                    xx = (i / 64) % 64 + 128;
                    x = i/4096+224;
                    printf("%c%c%c 0x%04x %ld\n", x, xx, xxx, i, zi[i]);

                }
            }
            
        }
    }
    
    else
    {
        printf("No repeat!\n");
    }
    
        return 0;
}
