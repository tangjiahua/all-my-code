//
//  main.cpp
//  C++_Test_Program
//
//  Created by 汤佳桦 on 2019/6/27.
//  Copyright © 2019 汤佳桦. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
double a[4];
int calculate(int n){
    if(n==1){
        if(fabs(a[0]-24.0)<0.001)//由于有精度值，有的计算后结果为24.0000000001却判定不是24
            return 1;
        return 0;
    }
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){//注意 不能重复出现数字！！！
            double x1,x2;
            x1=a[i]; x2=a[j];
            a[j]=a[n-1];
            
            a[i]=x1-x2;
            if(calculate(n-1))
                return 1;
            
            a[i]=x1+x2;
            if(calculate(n-1))
                return 1;
            
            a[i]=x2-x1;
            if(calculate(n-1))
                return 1;
            a[i]=x1*x2;
            if(calculate(n-1))
                return 1;
            if(x2){
                a[i]=x1/x2;
                if(calculate(n-1))
                    return 1;
            }
            if(x1){
                a[i]=x2/x1;
                if(calculate(n-1))
                    return 1;
            }
            a[i]=x1;
            a[j]=x2;
        }
    return 0;
}
int main(){
    while((cin >> a[0] >> a[1] >> a[2] >> a[3]) && (a[0] + a[1] + a[2] + a[3] != 0)){
        if(calculate(4))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
    return 0;
}
