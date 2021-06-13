#include "stdio.h"
int main()
{
  int a[10];
  int t;
  for(int i = 0; i<10; i++){
    scanf("%d",&a[i]);
  }

	w2`
      for(int i=0;i<9;i++)
    {
        int min=i;
        for(int j=i+1;j<10;j++)
            if(a[min]>a[j])
                min=j;
        if(min!=i)
        {
            t=a[min];
            a[min]=a[i];
            a[i]=t;
        }
    }

  for(int k = 0; k<9; k++)
    printf("%d,",a[k]);
  printf("%d\n",a[9]);
}
