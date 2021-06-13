#include "stdio.h"
#include "string.h"
int main()
{
  int n;                   //n means numbers of people
  scanf("%d",&n);
  getchar();
  char name[n][15];
  for(int i = 0; i<n; i++)
    gets(name[i]);

  int in, out, num, total[n], out1;
  char givename[15] = {0};
	for(int i = 0; i<n; i++)
		total[i] = 0;
	
  for(int i = 0; i<n; i++)
  {
    gets(givename);  //givename means who give money
    scanf("%d%d", &out, &num);
    getchar();
    
    
if(num != 0)
{
    char outname[num][15];			 //outname means people get money
    for(int j = 0; j<num; j++)
    {
      gets(outname[j]);
    }
	if(num != 0)	out1 = out/num;
	else out1 = 0;
  for(int k = 0; k<num; k++)  //give money to others
  {
    for(int l = 0; l<n; l++)
    {
      if(strcmp(name[l], outname[k]) == 0)
      {
        total[l] = total[l] + out1;
        break;
      }
    }
  }

  for(int l = 0; l<n; l++) //someone give others get the rest
  {
    if(strcmp(name[l], givename) == 0)
    {
      total[l] = total[l] - out1 * num;
      break;
    }
  }


	
	for(int k = 0; k<num; k++)
		strcpy(outname[k], "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
  }
else ;


}

  for(int k = 0; k<n; k++)
  {
    printf("%s %d\n", name[k], total[k]);
  }
  getchar();

}
