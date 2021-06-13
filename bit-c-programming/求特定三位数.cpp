#include "stdio.h"
#include "string.h"
int main()
{
  int n,m,damn;
  int num[9] = {1,2,3,4,5,6,7,8,9};
  int a,b,c,x;
  char ch[20];
  while(scanf("%d",&n)!=EOF)
  {
  	damn=0;
      for(int i=0; i<9; i++)
        {
          for(int j=0; j<9; j++)
          {
          	m=0;
            a=n*100+num[i]*10+num[j];
            b=2*a;
            c=3*a;
            int all = a+b*1000+c*1000000;
            sprintf(ch, "%d", all);
            for(int k=0; k<9; k++)
              for(int p=k+1; p<9; p++)
                if(ch[p] == ch[k]||ch[p]=='0'||ch[k]=='0'){
                	m=1;
                	goto fuck;
                }
        fuck:    if(m==0 && b/1000==0 && c/1000==0){
        	damn = 1;
        	printf("%d,%d,%d\n",a,b,c);
        }
          }

        }

      if(damn == 0) printf("0,0,0\n");

   }
}
