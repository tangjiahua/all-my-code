#include "stdio.h"
int main()
{
  int n;
  char ch;
  while(scanf("%d %c", &n ,&ch)!=EOF)
  {
  	if(n == 1)
	{
	printf("%c\n",ch);
	continue;	
	}
	  int i;
  char matrix[n][2*n-1];
  for(int k = 0; k<n; k++)
  	for(int l = 0; l<2*n-1; l++)
  		matrix[k][l] = ' ';
  for(int i = 0; i<n; i++)
  {
  	
    if(ch > 'Z')
      ch -= 26;
    matrix[i][i] = ch;
    matrix[i][2*n-2-i] = ch;
    ch++;
  }

  for(i = 1; i<n; i++)
  {
  	    if(ch > 'Z')
      ch -= 26;
    matrix[n-1][n-1-i] = ch;
    matrix[n-1][n-1+i] = ch;
     ch++;
  }

  for(i = 1; i< n-1; i++)
  {
     if(ch > 'Z')
      ch -= 26;
    matrix[n-1-i][0] = ch;
    matrix[n-1-i][2*n-2] = ch;
     	 ch++;
     	 
  }

  for(int k = 0; k<n; k++)
  {
    for(int l = 0; l< 2*n-1; l++)
    {
      if(l == 2*(n-1))
      {
        printf(" %c\n",matrix[k][l]);
      }
      else if(l == 0)
      	printf("%c",matrix[k][l]);
      else printf(" %c",matrix[k][l]);
    }
  }
}
}
