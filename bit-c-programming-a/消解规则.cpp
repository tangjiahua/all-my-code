
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h> 
#include<string.h> 
#define N 100 
int s[30][30]; 

int s0,s1,s2;
void save(char str[]);
int i_same(int a[],int b[]); 
int check(int c[]); 
int res(int a[],int b[]); 
int main() 
{int i,j; 
 char str[N]; 
 scanf("%s",str); 
 save(str);  
 do{ 
    s0=s1;s1=s2;
    for(i=0;i<=s0;i++) 
  for(j=s0+1;j<=s1;j++) 
    { 
        if(!res(s[i],s[j])) 
        {printf("NO\n"); 
       return 0;} 
   } 
      for(i=s0+1;i<=s1;i++) 
   for(j=i+1;j<=s1;j++) 
    { 
      if(!res(s[i],s[j])) 
    {printf("NO\n"); 
   return 0;} 
      } 
      
     } while(s2>s1);
  printf("YES\n"); 
   return 0; 
} 
void save(char str[]) 
{ 
   int i,j,len=strlen(str); 
   s0=s1=-1;s2=0;   
   for(i=0;i<30;i++)    for(j=0;j<30;j++) s[i][j]=0; 
   
    
   i=0;  
   while(i<len) 
   { 
    if(str[i]>='a'&&str[i]<='z') 
     s[s2][str[i]-'a']=1; 
     else if(str[i]=='&') s2++; 
     else if(str[i]=='!') 
     s[s2][str[++i]-'a']=2; 
     i++; 
   } 
} 
int i_same(int a[],int b[])
{ 
 int i; 
 for(i=0;i<26;i++) 
   if(a[i]!=b[i]) 
     return 0; 
  return 1; 
  
} 
int check(int c[])
{ 
    int i; 
 for(i=0;i<=s2;i++) 
  if(i_same(s[i],c)) 
 return 0; 
   
   return 1; 
} 
int res(int a[],int b[])
{ 
  int single=0;
   int couple=0;
    int c[30];
   int i; 
 for(i=0;i<26;i++) 
   {    
       if(!a[i]&&!b[i])  continue; 
        if((a[i]==1&&b[i]==2)||(a[i]==2&&b[i]==1)) couple++; 
       else single++; 
 } 
  if(couple!=1) return 1;
  if(!single)   return 0; 
    
   for(i=0;i<26;i++) 
   { 
      if((!a[i]&&!b[i])||(a[i]+b[i]==3)) c[i]=0; 
     else if (a[i]==1||b[i]==1) c[i]=1; 
     else c[i]=2; 
   } 
  if(check(c))
    { 
      s2++;
     for(i=0;i<26;i++) s[s2][i]=c[i]; 
    } 
  return 1; 
