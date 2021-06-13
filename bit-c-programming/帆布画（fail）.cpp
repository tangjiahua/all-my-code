#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <algorithm>
using namespace std;
long long n, s[100010];
long long ans = 0;
int cmp(const void *a, const void *b){
    return *(long long *)b - *(long long *)a;
}
void draw(long long x, long long y, long long length){
    if(x == y){
        return;
    }
    if(x+1 == y){
        ans = ans + s[x] + s[y];
        return;
    }
    draw(x, x + length / 2 - 1, length/2);
    draw(x + length / 2, y, length / 2);
    return;
}
int main(int argc, char const *argv[])
{
    int T = 0;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        scanf("%lld", &n);
        for (long long i = 0; i < n; i++){
            scanf("%lld", &s[i]);
            ans += s[i];
        }
        qsort(s, n, sizeof(long long), cmp);
        draw(0, n - 1, n);
        printf("%lld\n", ans);
    }
    return 0;
}
