#include "stdio.h"
int main()
{
  int n;
  char ch;
  scanf("%d %c",&n,&ch);
  char p[n][3*n-2];
  for(int l1 = 0; l1<n; l1++){
    for(int l2 = 0; l2<3*n-2; l2++){
      p[l1][l2] = ' ';
    }
  }
  
  //if(ch+i>90) ch-=26;
  for(int i = 0; i<n; i++){
  	if(ch+i>90) ch-=26;
    p[n-1][i] = ch+i;
    p[n-1-i][i] = ch+i;
  }
  for(int j = n; j<n+n-2; j++){
  	if(ch+j>90) ch-=26;
    p[0][j] = ch+j;
    p[n-1][j] = ch+j;
  }
  for(int k = n+n-2; k<3*n-2; k++){
  	if(ch+k>90) ch-=26;
    p[n-1][k] = ch+k;
    p[k-2*n+2][k] = ch+k;
  }

  for(int l1 = 0; l1<n; l1++){
    for(int l2 = 0; l2<3*n-2; l2++){
    	if(l2 > 3*n-2-n+l1){
        printf("\n");
        break;
      }
      else printf("%c",p[l1][l2]);
    }
  }
  printf("\n");
}
