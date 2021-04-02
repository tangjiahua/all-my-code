#include "string.h"
#include "stdio.h"
int leap_year( int );
int year_days( int );
int days(int,int,int);
char ch[5][9] = {"3 and 8.","4 and 9.","5 and 0.","1 and 6.","2 and 7."};
int main()
{
    int a1,b1,c1,a2,b2,c2,n,l;
    a1=2012; b1=4; c1=9;
   while( scanf("%d%d%d",&a2,&b2,&c2)!=EOF)
   {
   	strcpy(ch[0],"3 and 8.");
   	strcpy(ch[1],"4 and 9.");
   	strcpy(ch[2],"5 and 0.");
   	strcpy(ch[3],"1 and 6.");
   	strcpy(ch[4],"2 and 7.");
    if(a2>a1)
    {
        n=year_days(a1)-days(a1,b1,c1);
        for(l=a1+1;l<a2;l++)
        {
            n=n+year_days(l);
        }
        n=n+days(a2,b2,c2);
    }
    else
    {
        n=days(a2,b2,c2)-days(a1,b1,c1);
    }
    int k = 0;
    while((n-91)>=0)
    {
      k++;
      n = n-91;
    }
    for(int i = 0; i<k ;i++)
    {
      char change[9];
      strcpy(change, ch[4]);
      for(int j = 4; j>0; j--)
      {
        strcpy(ch[j],ch[j-1]);
      }
      strcpy(ch[0], change);
    }
    while((n-7) >= 0)
    {
      n = n-7;
    }
    if( n == 6 || n == 5)
      printf("Free.\n");
    else printf("%s\n",ch[n]);
}
}

int leap_year( int year )   // 判断闰年或平年
{   return ( (year%4==0 && year%100!=0) || year%400==0 ) ? 1 : 0;
}

int year_days(int year)     // 计算一整年的天数
{   return leap_year( year ) ? 366 : 365;
}

int days( int year, int month, int day ) // 计算该天month,day 是本年year的第几天
{   int months[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31}, i;

    if  ( leap_year( year ) && month >2 )
        day++;

    for ( i=1; i<month; i++ )
        day += months[i];

    return day;
}

