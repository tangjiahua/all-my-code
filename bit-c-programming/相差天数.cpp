#include <stdio.h>

// 声明函数原型
int leap_year( int );
int year_days( int );
int days(int,int,int);

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
int main()
{
    int a1,b1,c1,a2,b2,c2,n,l;
    scanf("%d%d%d",&a1,&b1,&c1);
    scanf("%d%d%d",&a2,&b2,&c2);
    if(a2>a1)
    {
        n=year_days(a1)-days(a1,b1,c1);
        for(l=a1+1;l<a2;l++)
        {
            n=n+year_days(l);
        }
        n=n+days(a2,b2,c2);
        printf("%d days\n",n);
    }
    else
    {
        n=days(a2,b2,c2)-days(a1,b1,c1);
        printf("%d days\n",n);
    }
}
