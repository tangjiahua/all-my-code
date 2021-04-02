#include "stdio.h"
int func(int n, int x);
int main()
{
	int n = 7, x = 2;
	func(n, x);
  printf("\n");
}

int func(int n, int x){
  if(n == 0) {
    printf("sum=%d\n",x);
  }
  else {
    func(--n, (x+1)*2);
    printf("sell=%d,",x+2);
  }
}
