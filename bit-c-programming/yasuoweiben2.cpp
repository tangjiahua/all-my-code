#include "stdio.h"
#include "ctype.h"
#include "string.h"
int main()
{
  char ch;
  char a[30] = {0};
  char list[5000][30] = {0};
  int i = 1, j = 2, g = 0;
  while((ch = getchar()) != EOF)    //Please, please do it--it would please Mary very,
  {
    if(isalpha(ch)==0)
    {
    	putchar(ch);
		continue;
    }

    else
	{
    	i = 1;
   	 	a[0] = ch;
    	g = 0;
    	while(ch = getchar())
    	{
    		if(isalpha(ch) != 0)
    	  	{
    	  		a[i] = ch;
    	  		i++;
    	  	}
    	  	else break;
    	}

    	
    	
    	for(int k = 1; k<j; k++)
    		{
    		  if(strcmp(list[k], a) == 0)
    		  {
    		  	printf("%d",k);
    	 	 	g = 1;
     		 	putchar(ch);
     		 	for(int e=0;e<30;e++)
    	  	      a[e]='\0';
    	  	    break;
     		  }	
     		}
     	if(g == 0)
     		  {
     		  	
     	 		strcpy(list[j-1], a);
    	        j++;
    	        for(int e=0;e<i;e++)
    	 	    putchar(a[e]);
    	 	 	for(int e=0;e<30;e++)
    	  	      a[e]='\0';
	 	 	    putchar(ch);
     		  }
   			}
   			
		
	}

  	

}
