#include "stdio.h"
#include "string.h"
#include "ctype.h"
int main()
{
  char ch[80];
  char list[50][10] = {'\0'}; //Please, please do it--it would please Mary very,

  int k = 1, j = 0;
  while(gets(ch)!=NULL)
  {
    for(int i = 0; i<strlen(ch); i++)
    {
      if(isalpha(ch[i])!=0)
      {
        while(isalpha(ch[i+j])!=0)
        {
          list[k][j] = ch[i+j];
          j++;
        }
        k++;
        i = i+j-1;
        j = 0;
      }
    }
    int g = 0;
    for(int i = 0; i<strlen(ch); i++)    //对ch挨个统计
    {
      g = 0;
      for(int m = 0; m<k; m++)  //m为每次都要对一个字符检查是否为list中某元素首字符
      {
        if(ch[i] == list[m][0]) //Please, please do it--it would please Mary very,
        {
          int d= strlen(list[m]);
          char check[d];
          for(int p = 0; p<d; p++)
          {
            check[p] = ch[i+p];
          }
          if(strcmp(check, list[m]) == 0)
          {
            printf("%d",k);
            g = 1;
          }
        }

      }
      if(g == 0)
      {
        putchar(ch[i]);
      }

    }
  }
}
