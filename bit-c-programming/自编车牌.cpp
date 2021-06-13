#include "stdio.h"
int main()
{
  char ch[5];
  while(gets(ch)!=NULL)
  {
    if(ch[4]>='0' && ch[4]<='9')
    {
      int p=0;
      for(int i=0; i<4; i++)
      {
        if(ch[i]>='A' && ch[i]<='H' || ch[i]>='J' && ch[i]<'O' || ch[i]>'O' && ch[i]<='Z')
          p++;
      }
      if(p == 2)
      {
        printf("ok.\n");
        continue;
      }
    }
  	printf("no.\n");
  }
}
