#include "string.h"
#include "stdio.h"
int main()
{
  char ch[20], *p, *q;
  gets(ch);
  p = ch;
  q = ch + strlen(ch) - 1;

  while(p<q){
    if(*p != *q){
    	printf("NO\n");
    	break;
    }
    else{
	p++;
	q--;
    }
  }
  if(p>=q) printf("YES\n");
}
