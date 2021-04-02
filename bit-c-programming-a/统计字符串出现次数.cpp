#include "stdio.h"
#include "string.h"
int main()
{
  int count = 0;
  char ch[1000]={0}, str[100] = {0};
  gets(ch);
  gets(str);
  int l = strlen(ch);
  int d = strlen(str);
  char a[d+1];
  for(int l = 0; l<d+1; l++)
  	a[l] = '\0';
  for(int i = 0; i<l; i++)
  {
    if(ch[i] == str[0])			//This is his book
    {
      i++;
      a[0] = str[0];
      for(int j = 1; j<d; j++)
        {
          a[j] = ch[i];
          i++;
        }
      if(strcmp(a, str) == 0) count++;
    }
  }
  if(count == 0) printf("No\n");
  else printf("%d\n",count);
}
