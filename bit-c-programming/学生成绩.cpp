
#include "stdio.h"

int main()
{
  char ch;
  ch = getchar();
  if(ch == '1') printf("80\n");
  if(ch == '2') printf("85\n");
  if(ch == '3') printf("79\n");
  if(ch == 'm') printf("2\n");
  if(ch > '3' && ch !='m') printf("0\n");
}
