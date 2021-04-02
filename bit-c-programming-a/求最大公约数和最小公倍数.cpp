#include "stdio.h"
int func1(int a, int b);//姹傛渶澶у叕绾︽暟
int func2(int a, int b);//姹傛渶灏忓叕鍊嶆暟
int main()
{
  int x, y;
  scanf("%d,%d",&x,&y);
  printf("最大公约数：%d\n", func1(x, y));
  printf("最小公倍数：%d\n", func2(x, y));
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
