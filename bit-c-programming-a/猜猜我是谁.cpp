#include "stdio.h"
#include "string.h"
int main()
{
  char file_name[20];
  char s[15];
  int n, flag = 0;
  FILE *fp;
  scanf("%s",file_name);
  if((fp = fopen(file_name, "r")) == NULL){
    printf("File Name Error.\n");
    exit(0);
  }
  else {
    scanf("%d",&n);
    for(int i = 0; i<n; i++){
      if(fgets(s, 19, fp) == NULL){
        printf("Line No Error.\n");
                flag = 1;
        break;

      }
    }
    if(flag ==0) printf("%s",s);
    }
  fclose(fp);
}
 
