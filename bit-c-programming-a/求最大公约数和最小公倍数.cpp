#include "stdio.h"
int func1(int a, int b);//求最大公约数
int func2(int a, int b);//求最小公倍数
int main()
{
  int x, y;
  scanf("%d,%d",&x,&y);
  printf("���Լ����%d\n", func1(x, y));
  printf("��С��������%d\n", func2(x, y));
  return 0;
}

int func1(int a, int b){
  if(a > b){
    if(b == 0) return a;
    return func1(b, a%b);
  }
  else if(a ==b) return a;
  else {
    if(a == 0) return b;
    return func1(a, b%a);
  }
}

int func2(int a, int b){
	int big;
  int big1 = big = a>b?a:b;
  int small = a>b?b:a;
  while(big%small != 0 || big%big1 !=0 ){
	big++;
  }
  return big;
}
