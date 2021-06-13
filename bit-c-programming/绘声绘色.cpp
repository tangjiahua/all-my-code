#include "stdio.h"
#include<iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;
int main() 
{
    priority_queue<long long> a; //大顶堆
    priority_queue<long long, vector<long long>, greater<long long> > b;  //小顶堆
    stack<long long> c;//栈
    queue<long long> d;//队列
    int n;
    while(scanf("%d",&n) != EOF){
        long long op, x, xa, xb, xc, xd;
        int flaga = 1, flagb = 1, flagc = 1, flagd = 1;
        while(n--){
            scanf("%lld%lld",&op,&x);
            if(op == 1){
                a.push(x);
                b.push(x);
                c.push(x);
                d.push(x);
            }
            else{
                if(a.empty()||b.empty()||c.empty()||d.empty()){
                    flaga = 0;
                    flagb = 0;
                    flagc = 0;
                    flagd = 0;
                    break;
                }
                else{
                    xa = a.top();
                    xb = b.top();
                    xc = c.top();
                    xd = d.front();
                    a.pop();
                    b.pop();
                    c.pop();
                    d.pop();
                }
                if(xa != x) flaga = 0;
                if(xb != x) flagb = 0;
                if(xc != x) flagc = 0;
                if(xd != x) flagd = 0;
            }
        }
        if(flaga+flagb+flagc+flagd > 1)
            printf("not sure\n");
        else if(flaga+flagb+flagc+flagd == 0) printf("pool zls\n");
        else if(flaga == 1) printf("big priority queue\n");
        else if(flagb == 1) printf("small priority queue\n");
        else if(flagc == 1) printf("stack\n");
        else if(flagd == 1) printf("queue\n");

        while(!a.empty()){
            a.pop();
        }
        while(!b.empty()){
            b.pop();
        }
        while(!c.empty()){
            c.pop();
        }
        while(!d.empty()){
            d.pop();
        }
    }
    return 0;
}