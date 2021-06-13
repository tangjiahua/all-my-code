#include <stdio.h>
#define N 5
int main ( )

{ int i, j, m ;

  for ( i=1; i<=N; i++ )      

  {  for( j=1; j<=N; j++ ) 

        printf(" %d",     (i+j-2)/N+1      );

     printf("\n");

  }

}
