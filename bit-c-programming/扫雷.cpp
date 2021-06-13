#include "stdio.h"
int main()
{
    int m, n, k = 1;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
    	if(m ==0 && n ==0)
    	{
    		break;
    	}
    	if(k>1) printf("\n");
    	getchar();
      char boom[m][n];
      for(int i = 0; i<m ;i++)
        {
          for(int j = 0; j<n; j++)
            {
              boom[i][j] = getchar();
            }
          getchar();
        }

	  printf("Field #%d:\n",k);
      for(int i = 0; i<m; i++)
      {
        for(int j = 0; j<n; j++)
        {
          if(boom[i][j] == '*') printf("*");
          else
          {
            int num = 0;
            int a1 = i-1, a2 = i+1;
            int b1 = j-1, b2 = j+1;
            if(a1 < 0) a1 = 0;
            if(a2 > m-1) a2 = m-1;
            if(b1 < 0) b1 = 0;
            if(b2 > n-1) b2 = n-1; 
            int z = b1;
            for(; a1<=a2; a1++)
            {
              for(; b1<=b2; b1++)
              {
                if(boom[a1][b1] == '*') num++;
              }
              b1 = z;
            }
            printf("%d",num);
          }
        }
        printf("\n");
      }
      k++;
    }
}
