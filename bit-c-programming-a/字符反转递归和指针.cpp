#include "stdio.h"
void reverse(char *p){
  char *q = p;
  while(*q != '\0')
    q++;
  q--;
  if(p<q){
    char change = *p;
    *p = *q;
    *q = '\0';
    reverse(p+1);
    *q = change;
  }

}

int main()
{
  char ch[100];
  while(gets(ch)!=NULL){
    reverse(ch);
    printf("%s\n",ch);
  }
}
