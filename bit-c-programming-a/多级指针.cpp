#include "stdio.h"
int main()
{
  char *pc[] = {"hello","world"};
  char **p;
  for(int i=0; i<2; i++){
    printf("%s\n",*(pc+i));
  }
}
