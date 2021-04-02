#include "stdio.h"
#include "string.h"
int main()
{
    int n = 0, len, p1, p2;
    char hf[10] = {'f', 'a', 't', 't', 'y', 'h', 'a', 'p', 'p', 'y'}, ch1, ch2;

    scanf("%d",&n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char ch[1100];
        memset(ch, '\0', sizeof(ch));
        scanf("%s", &ch);
        len = strlen(ch);

        int flag = 0;
        for (int j = 0; j < len; j++)//从头开始
        {
            int count = 0;
            flag = 0;

            for(int k = 0; k < 10; k++)
            {
                if(ch[j+k] != hf[k] && count == 0)
                {
                    ch1 = hf[k];//ch1为需要的字符
                    p1 = j + k;//p1为原字符所在的位置
                    count++;
                }
                else if(ch[j+k] != hf[k] && count == 1)
                {
                    count++;
                    p2 = j + k;
                    ch2 = hf[k];
                }
                else if(ch[j+k] !=hf[k] && count >1)
                    count++;
            }
            if(count == 0)
            {
                printf("%d %d\n",j+4,j+3);
                flag = 1;
                break;
            }
            else if(count == 1)
            {
                for (int l = 0; l < len;l++)
                {
                    if(l == j) 
                    {
                        l = l + 9;
                        continue;
                    }
                    if(ch[l] == ch1)
                    {
                        printf("%d %d\n", l+1, p1+1);
                        flag = 1;
                        break;
                    }
                    
                }
                if(flag == 1)
                    break;
            }
            else if(count == 2)
            {
                if(ch[p1] == ch2 && ch[p2] == ch1)
                {
                    printf("%d %d\n", p1+1, p2+1);
                    flag = 1;
                    break;
                }
                
            else
            {
                continue;
            }
                
            }
            
        

        }
        if(flag == 0)
            printf("-1\n");
    }
    return 0;
}
