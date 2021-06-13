#include "stdio.h"

struct student
{
  char name[10];
  int score;
  char level;
  int top;
}id[5];

int main()
{
    char ch;
    int j, max = 0, paiming = 1, x, y;
    for(int i = 0; i<5; i++)
    {
      j = 0;
      while(ch = getchar())
      {
      	if(ch != ',')
      	{
    		id[i].name[j] = ch;
       		j++;
      	}
		else break;
      }
      scanf("%d",&id[i].score);
      getchar();
    }

    for(int i = 0; i<5; i++)
    {
      if(id[i].score < 60) id[i].level = 'F';
      if(id[i].score >= 60) id[i].level = 'D';
      if(id[i].score >= 70) id[i].level = 'C';
      if(id[i].score >= 80) id[i].level = 'B';
      if(id[i].score >= 90) id[i].level = 'A';
    }

    for(int i = 0; i<5; i++)
    {
      max = 0;
      for(j = 0; j<5; j++)
      {
        if(id[j].score > max)
        {
          max = id[j].score;
          x = j;
        }
      }
      id[x].top = paiming;
      y = 0;
      for(int k = 0; k<5; k++)
      {
        
        if(k == x) continue;
        if(id[k].score == max)
        {
          id[k].top = paiming;
          id[k].score = 0;
          y++;
        }
      }
      paiming++;;
      id[x].score = 0;
      i = i+y;
    }

    for(int i = 0; i<5; i++)
    {
      printf("%s-%c-%d\n",id[i].name, id[i].level, id[i].top);
    }
}
