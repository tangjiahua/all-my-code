#include "stdio.h"
/*53010219200508011X*/
int main()
{
	char num[18];
	int y,m,d,m2,dmax,q;
	int i,j,judge;
	char right;

	while(gets(num)!=NULL)
	{
		
		i=0;
		j=0;
		for(q=0;q<17;q++)
		{
			num[q]=num[q]-48;
		}
 		y=num[6]*1000+num[7]*100+num[8]*10+num[9];
		m=num[10]*10+num[11];
		d=num[12]*10+num[13];
		if(y%4==0&&y%100==0||y%400==0) m2=29;
		else m2=28;
		switch(m)
		{
			case 2: if(d>m2) i=1; break;
			case 4:
			case 6:
			case 9:
			case 11: if(d>30) i=1; break;
			
		}
		if(d>31||d==0||m==0||m>12) i=1;
		
		
		judge=num[0]*7+num[1]*9+num[2]*10+num[3]*5+num[4]*8+num[5]*4+num[6]*2+num[7]+num[8]*6+num[9]*3+num[10]*7+num[11]*9+num[12]*10+num[13]*5+num[14]*8+num[15]*4+num[16]*2;
		judge=judge%11;
		switch(judge)
		{
			case 0: right='1'; break;
			case 1: right='0';break;
			case 2: right='X';break;
			case 3: right='9';break;
			case 4: right='8';break;
			case 5: right='7';break;
			case 6: right='6';break;
			case 7: right='5';break;
			case 8: right='4';break;
			case 9: right='3';break;
			case 10: right='2';break;
		}
		if(right!=num[17]) j=1;
		if(i==1&&j==1) printf("Invalid birthday and check code\n");
		if(i==1&&j==0) printf("Invalid birthday\n");
		if(i==0&&j==1) printf("Invalid check code\n");
		if(i==0&&j==0) printf("Passed\n");
	}
}
