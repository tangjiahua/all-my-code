#include "stdio.h"
int main()
{
  int n; //how many students
  scanf("%d\n", &n);
  struct student
  {
    char name[30];
    int score;
  }id[n], change;

  for(int i = 0; i<n; i++){
    int j = 0;
    while(id[i].name[j] = getchar()){
    	if(id[i].name[j] == ','){
    		id[i].name[j] = '\0';
			break;	
    	}
    	else j++;
    }
    
    scanf("%d",&id[i].score);
    getchar();
  }

  for(int i = 0; i<n-1; i++){
    for(int j = 0; j<n-1-i; j++){
      if(id[j].score < id[j+1].score){
        change = id[j];
        id[j] = id[j+1];
        id[j+1] = change;
      }
    }
  }

  for(int k = 0; k<n; k++){
    printf("%s,%d\n",id[k].name, id[k].score);
  }
}
