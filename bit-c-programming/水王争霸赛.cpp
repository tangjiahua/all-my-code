#include "stdio.h"
#include "string.h"
int main()
{
  int n;
  scanf("%d",&n);
  getchar();
  struct fuck
  {
    char name[20];
    char num[10000];
    int d;
  }id[n], change;

  for(int i = 0; i<n; i++){
     gets(id[i].name);
     gets(id[i].num);
     id[i].d = strlen(id[i].num);
  }

  for(int i = 0; i<n-1; i++)
    for(int j = 0; j<n-1-i; j++){
      if(id[j].d == id[j+1].d){
        if(strcmp(id[j].num, id[j+1].num) < 0){
          change = id[j];
          id[j] = id[j+1];
          id[j+1] = change;
        }
        if(strcmp(id[j].num, id[j+1].num) == 0){
        	if(strcmp(id[j].name, id[j+1].name) > 0){
                change = id[j];
        		id[j] = id[j+1];
        		id[j+1] = change;		
        	}
        }
      }

      else if(id[j].d < id[j+1].d){
        change = id[j];
        id[j] = id[j+1];
        id[j+1] = change;
      }
	
    }

  for(int i = 0; i<n; i++){
    puts(id[i].name);
  }
}
