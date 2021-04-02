#include "stdio.h"
#include "stdlib.h"
#include <vector>
#include <algorithm>
#include <queue>
#include <bits/stdc++.h>
#include<iostream>
using namespace std;
int cmp(const void *a, const void *b){
    return *(long long *)b - *(long long *)a;
}
long long a[500005];
int main()
{
    queue<long long> d;//队列
    vector<long long> x(10,0)
    long long n, t, t1, count = 0;
    scanf("%lld",&n);
    for (long long i = 0; i < n; i++){
        scanf("%lld", &a[i]);
    }
    if(n == 3){
        printf("%lld\n", a[0] + a[1] + a[2]);
        return 0;
    }
    qsort(a, n, sizeof(long long), cmp);
    for (long long i = 0; i < n; i++){
        d.push(a[i]);
    }
    while(!d.empty()){
        if(d.front() == 0){
            d.pop();
            x.push_back(0);
            count+=2;
            continue;
        }
        t = d.front();
        d.pop();
        x.push_back(t);
        while(!d.empty()){
            t1 = d.front();
            
            while(t == t1){
                d.pop();
                d.push(t1);
                t1 = d.front();
            }
            if(t1 == 0){
                d.pop();
                x.push_back(0);
                count+=2;
                break;
            }
            if(t-1 == t1){
                x[count] = x[count] + t1;
                t = t1;
                d.pop();
            }
            else{
                d.pop();
                d.push(t1);
                count++;
                break;
            }
        }
    }
    sort(x.begin(), x.end(), greater<long long>());
    if(count < 2){
        
    }
    printf("%lld\n", x[0] + x[1] + x[2]);
    return 0;
}