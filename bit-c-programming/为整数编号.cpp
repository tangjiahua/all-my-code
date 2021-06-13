#include <stdio.h>
struct nn
{  int no;
   int num;
};

typedef struct nn DATA;

int number( char * , DATA []);

int main( )
{
   DATA b[100];
   char sa[500];
   int i, n;
   gets( sa );
   n = number( sa, b );
   for ( i=0; i<n; i++ )
       printf("%d %d\n", b[i].num, b[i].no );
   return 0;
}

int number( char * str, DATA a[] ) //4 3 6 8 2 3 9
{
  int i = 0, k = 0, p = 1, q, max = 9999;
  while(*str != '\0'){
    if(*str == ' ') str++;
    else
    {
      if(*str == '-')
      {
        str++;
        int o = 0;
        while(*str != ' ' && *str != '\0')
        {
          o = o*10 - *str + 48;
          str++;
        }
        a[i].num = o;
        i++;
      }
      else{
        int o = 0;
        while(*str != ' ' && *str != '\0')
        {
          o = o*10 + *str - 48;
          str++;
        }
        a[i].num = o;
        i++;
      }
    }
  }

  DATA b[i];
  for(int j = 0; j<i; j++)
  {
    b[j].num = a[k++].num;
  }
  for(int m = 0; m<i; m++)
  {
    for(int n = 0; n<i; n++)
    {
      if(b[n].num < max)
      {
        q = n;
        max = b[n].num;
      }
    }
    a[q].no = p++;
    b[q].num = 99999;
    max = 9999;
  }
	return i;
}
