#include<stdio.h>
#include "string.h"
int main()
{
	char a[19];
	while(gets(a))
	{
	if(strlen(a)==18)
	{
	int n1,n2,i=0,j=1,y,m,d,p;
	n1=(a[0]-'0')*7+(a[1]-'0')*9+(a[2]-'0')*10+(a[3]-'0')*5+(a[4]-'0')*8+(a[5]-'0')*4+(a[6]-'0')*2+(a[7]-'0')*1+(a[8]-'0')*6+(a[9]-'0')*3+(a[10]-'0')*7+(a[11]-'0')*9+(a[12]-'0')*10+(a[13]-'0')*5+(a[14]-'0')*8+(a[15]-'0')*4+(a[16]-'0')*2;
	n2=n1%11;
	switch(n2)
	{
		case 0:if (a[17]=='1') i=1;
		       else i=0;break;
		case 1:if (a[17]=='0') i=1;
		       else printf("Invalid\n");break;
		case 2:if (a[17]=='X') i=1;
		       else i=0;break;
		case 3:if (a[17]=='9') i=1;
		       else i=0;break;
		case 4:if (a[17]=='8') i=1;
		       else i=0;break;
		case 5:if (a[17]=='7') i=1;
		       else i=0;break;
		case 6:if (a[17]=='6') i=1;
		       else i=0;break;
		case 7:if (a[17]=='5') i=1;
		       else i=0;break;
		case 8:if (a[17]=='4') i=1;
		       else i=0;break;
		case 9:if (a[17]=='3') i=1;
		       else i=0;break;
		case 10:if (a[17]=='2') i=1;
		       else i=0;break;
		default:;
	}
	y=(a[6]-'0')*1000+(a[7]-'0')*100+(a[8]-'0')*10+a[9]-'0';
	m=(a[10]-'0')*10+a[11]-'0';
	d=(a[12]-'0')*10+a[13]-'0';
	p=(y-1901)%4;
	if(y>2017) j=0;
	switch(m)
		{
			case 12:if(d<0||d>31) j=0;break;
			case 11:if(d<0||d>30) j=0;break;
		    case 10:if(d<0||d>31) j=0;break;
		    case 9:if(d<0||d>30) j=0;break;
	 	    case 8:if(d<0||d>31) j=0;break;
		    case 7:if(d<0||d>31) j=0;break;
		    case 6:if(d<0||d>30) j=0;break;
		    case 5:if(d<0||d>31) j=0;break;
		    case 4:if(d<0||d>30) j=0;break;
		    case 3:if(d<0||d>31) j=0;break;
		    case 2:if(p==3){if(d<0||d>29) j=0;break;}
		           else{if(d<0||d>28) j=0;break;}break;
		    case 1:if(d<0||d>31) j=0;break;
		    default:j=0;break;
		}
    if(i==1&&j==1)
    printf("Valid\n");
    else if(i==1&&j==0)
    printf("Invalid\n");
    else if(i==0&&j==1)
    printf("Invalid\n");
    else
    printf("Invalid\n");
	}
	}
	else
	{
		
	}
	

}

