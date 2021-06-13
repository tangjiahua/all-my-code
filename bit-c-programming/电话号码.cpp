#include "stdio.h"
#include "stdlib.h"
#include "string.h"
int map[7000000];//非常重要！！！！！

int main(int argc, char const *argv[])
{   
    char ch[25];
    memset(ch, '\0', sizeof(ch));
    int flag1 = 0; //flag1就是如果error有，则为1，然后输出Not found
    int x = 0;//x为存储的号码的数量
    printf("Error:\n");
    while(scanf("%s",ch) != EOF)
    {
        //一遇错误就输出，不错就存储
        int flag2 = 0;
        for (int i = 0; i< strlen(ch); i++)
        {
            if(ch[i] == '-')
                continue;
            else
            {
               if(ch[i] != '3' && ch[i] != '6' && ch[i] != 'D' && ch[i] != 'E' && ch[i] != 'F' && ch[i] != 'M' && ch[i] != 'N' && ch[i] != 'O') 
               {
                   puts(ch);
                   flag2 = 1;
                   flag1 = 1;
                   break;
               }
               else
               {
                   break;
               }
            }
        }
        if(flag2 == 1)
        {
            memset(ch, '\0', sizeof(ch));
            continue;
        }
            
        flag2 = 0;
        //如果判断有Q与Z则flag2为1，直接continue；
        for (int i = 0; i < 20; i++)
        {
            if(ch[i] == 'Q' || ch[i] == 'Z')
            {
                puts(ch);
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }
        if(flag2 == 1)
            {
                memset(ch, '\0', sizeof(ch));
                continue;
            }
        else//否则就一定是正确的号码 先存储进number1，在判断是否有重复的！
        {
            for (int i = 0; i < 20; i++) //将这个电话变成标准形式
            {
                switch(ch[i])
                {
                    case 'A': ch[i] = '2'; break;
                    case 'B': ch[i] = '2'; break;
                    case 'C': ch[i] = '2'; break;
                    case 'D': ch[i] = '3'; break;
                    case 'E': ch[i] = '3'; break;
                    case 'F': ch[i] = '3'; break;
                    case 'G': ch[i] = '4'; break;
                    case 'H': ch[i] = '4'; break;
                    case 'I': ch[i] = '4'; break;
                    case 'J': ch[i] = '5'; break;
                    case 'K': ch[i] = '5'; break;
                    case 'L': ch[i] = '5'; break;
                    case 'M': ch[i] = '6'; break;
                    case 'N': ch[i] = '6'; break;
                    case 'O': ch[i] = '6'; break;
                    case 'P': ch[i] = '7'; break;
                    case 'R': ch[i] = '7'; break;
                    case 'S': ch[i] = '7'; break;
                    case 'T': ch[i] = '8'; break;
                    case 'U': ch[i] = '8'; break;
                    case 'V': ch[i] = '8'; break;
                    case 'W': ch[i] = '9'; break;
                    case 'X': ch[i] = '9'; break;
                    case 'Y': ch[i] = '9'; break;
                }
            }
            int i = 0, k = 6, k1, p, j = 0;
            while(i < strlen(ch))//存储进Number1
            {
                if(ch[i]!='-')
                {
                    p = ch[i] - '0';
                    k1 = 0;
                    while(k1++<k)
                    {
                        p *= 10;
                    }
                    j = j + p;
                    k--;
                    i++;
                    continue;
                }
                else
                {
                    i++;
                    continue;
                }
            }
            //判断是否有重复！
            map[j]++;
        }
        memset(ch, '\0', sizeof(ch));
    }
    if(flag1 == 0)
        printf("Not found.\n");
    printf("\nDuplication:\n");
    int flag5 = 0;//flag5用来判断是否Duplication为notfound
    for (int i = 3000000; i < 4000000;i++)
    {
        if(map[i]>1)
        {
            printf("%d-%04d %d\n", i / 10000, i % 10000, map[i]);
            flag5 = 1;
        }
    }
    for (int i = 6000000; i < 7000000;i++)
    {
        if(map[i]>1)
        {
            printf("%d-%04d %d\n", i / 10000, i % 10000, map[i]);
            flag5 = 1;
        }
    }
        if (flag5 == 0)
            printf("Not found.\n");

    return 0;
}
