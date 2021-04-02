#include "stdio.h"
#include "stdlib.h"
typedef struct hole{
    long long number;
    long long width;
    long long height;
    struct hole *pre;
    struct hole *next;
} myhole;

long long ans[100005];

int main(){
    myhole *left, *right, *prehole, *cur, *deep;
    long long n;
    long long a, b;
    left = (myhole *)malloc(sizeof(myhole));
    left->width = 0;
    left->height = 1000005;
    left->pre = left->next = NULL;
    prehole = left;
    deep = left;
    scanf("%lld", &n);

    for (long long i = 0; i < n; i++){
        scanf("%lld%lld", &a, &b);
        cur = (myhole *)malloc(sizeof(myhole));
        cur->width = a;
        cur->height = b;
        cur->pre = prehole;
        cur->next = NULL;
        cur->number = i;
        prehole->next = cur;
        prehole = cur;

        if(deep->height > b)
            deep = cur;
    }

    right = (myhole *)malloc(sizeof(myhole));
    right->width = 0;
    right->height = 1000005;
    right->pre = cur;
    cur->next = right;
    right->next = NULL;


    //开始计算覆盖的需要时间
    long long time = 0;
    while(deep->pre->height != deep->next->height){
        ans[deep->number] = time + deep->width;
        if(deep->pre->height > deep->next->height){
            time = time + (deep->next->height - deep->height) * deep->width;
            deep->next->width += deep->width;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->next;
        }
        else{
            time = time + (deep->pre->height - deep->height) * deep->width;
            deep->pre->width += deep->width;
            deep->pre->next = deep->next;
            deep->next->pre = deep->pre;
            deep = deep->pre;
        }

        if(deep->height < deep->pre->height && deep->height < deep->next->height)
            continue;
        else if(deep->pre->height > deep->next->height){
            while(deep->height > deep->next->height)
                deep = deep->next;
        }
        else{
            while(deep->height > deep->pre->height)
                deep = deep->pre;
        }
    }
    ans[deep->number] = time + deep->width;

    for (long long i = 0; i < n; i++){
        printf("%lld\n", ans[i]);
    }
}