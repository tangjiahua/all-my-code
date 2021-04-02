#include<iostream>
using namespace std;
 
int main(){
    int i,j,a[4][4];
    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            cin>>a[i][j];
    for (j=3;j>=0;j--)
    {
        for (i=0;i<4;i++)
        {
            cout.width(3);
            cout<<a[i][j];
        }
        cout<<endl;
    }
    return 0;
}