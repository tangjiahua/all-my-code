#include <stdio.h>

int sumn( int n, int *flag);

int main()
{
    int n, nf=0;
    scanf("%d",&n);
    printf("%d\n",sumn(n, &nf) );
    if(nf!=n)
        printf("Error:%d\n",nf);
    return 0;
}

int sumn( int n, int *flag)
{
	(*flag)++;
  if(n == 1) return 1*2;
  else{
    return n*(n+1)+sumn(n-1, flag);
  }
}
