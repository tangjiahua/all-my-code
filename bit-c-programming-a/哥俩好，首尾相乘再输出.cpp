#include "stdio.h"
int main()
{
  int n, i, k = 0;
  scanf("%d",&n);
  int a[n], b[(n+1)/2];
  for(i = 0; i<n; i++)
    scanf("%d",&a[i]);
	i--;
  for(int l = 0; l<(n+1)/2; l++)
  {
  	if(l == i){
  		b[l] = a[l];
  	}
  	else{
  		
  	
    b[l] = a[l]*a[i];
    i--;
}
  }

  for(int l = 0; l<(n+1)/2; l++)
  {
    printf("%d ",b[l]);
  }
  printf("\n");
}
