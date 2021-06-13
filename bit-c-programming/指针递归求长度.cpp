#include "stdio.h"
int str(char *p);
int  main()
{
  char ch[100];
  char *p;
  while(scanf("%s",ch)!=EOF){
    p = ch;
    printf("the length of it is %d.\n",str(p));
  }
}

int str(char *p){
  if(*p == '\0') return 0;
  else{
    return 1+str(p+1);
  }
}
