#include "stdio.h"
int func(int n);
int main()
{
  int n;
  scanf("%d",&n);

  func(n);
}

int step = 0;
int func(int n){
	if(n == 1){
    printf("%d\nstep=%d\n",n,step+1);
  }

  else if(n%2 == 0){
    step++;
         printf("%d,",n);
     n/=2;

     func(n);
   }
  else if(n%2 == 1){
    step++;
        printf("%d,",n);
    n = n*3 + 1;

    func(n);
  }

}
