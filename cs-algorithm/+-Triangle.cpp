#include <iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

class Triangle
{
    friend int Calculate(int);
private:
    void Back(int t);
    int n,        
    count_half,       
    count_plus,        //当前"+"
    **p;          //矩阵
    long count_sum;
};


void Triangle::Back(int t)
{
    if((count_plus >count_half)||( count_half<t*(t-1)/2-count_plus))
        return;

    if(t>n) count_sum++;
    else
        for(int i=0; i<2; i++)
        {
            p[1][t]=i;
            count_plus+=i;
            for(int j=2; j<=t; j++)
            {
                p[j][t-j+1]=p[j-1][t-j+1]^p[j-1][t-j+2];
                count_plus+=p[j][t-j+1];
            }
            Back(t+1);
            for(int j=2; j<=t; j++)
                count_plus-=p[j][t-j+1];

            count_plus-=i;
        }
}

int Calculate(int n)
{

    Triangle X;
    X.n=n;
    X.count_plus=0;
    X.count_sum=0;
    X.count_half=n*(n+1)/2;
    if(X.count_half%2 != 0) return 0; 
    X.count_half=X.count_half/2;

    int **p=new int *[n+1];

    for(int i=0; i<=n; i++)                   
        p[i]=new int[n+1];  

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            p[i][j]=0;
    X.p=p;
    X.Back(1);
    return X.count_sum;
}
int main()
{

    int n,result;
    while(cin>>n)
    {
        result=Calculate(n);
        cout<<result<<endl;

    }

    return 0;
}