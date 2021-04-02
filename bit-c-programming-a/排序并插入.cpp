#include "stdio.h"
int func1(int b[10]);
int main()
{
  int a[10];
  scanf("%d,%d,%d,%d,%d,%d,%d,%d,%d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8]);
  func1(a);
}

int func1(int b[10])
{
  int p;
  scanf("%d",&b[9]);
		for(int i=0;i<10-1;i++)
			for(int j=0;j<10-i-1;j++)
			{
				if(b[j]>b[j+1])
				{
					p=b[j];
					b[j]=b[j+1];
					b[j+1]=p;
				}
			}
  for(int i = 0; i<9; i++)
    printf("%d,",b[i]);
  printf("%d\n",b[9]);

}
