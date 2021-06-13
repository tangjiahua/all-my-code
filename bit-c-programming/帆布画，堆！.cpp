# include<stdio.h>
# include<stdlib.h>
long long h[100010];
long long n, ans;
void swap(long long  x, long long y){
    long long t;
    t = h[x];
    h[x] = h[y];
    h[y] = t;
}
void siftdown(int i){
    long long t, flag = 0;
    while(i*2 <= n && flag == 0){
        if(h[i] > h[i*2])
            t = i * 2;
        else
            t = i;
        if(i*2+1 <= n){
            if(h[t] > h[i*2+1])
                t = i * 2 + 1;
        }
        if(t!=i){
            swap(t, i);
            i = t;
        }
        else
            flag = 1;
    }
}
void create(){
    long long i;
    for (i = n / 2; i >= 1;i--){
        siftdown(i);
    }
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        ans = 0;
        long long i, num;
        scanf("%lld", &num);
        for (i = 1; i <= num; i++)
            scanf("%lld", &h[i]);
        if(num == 1){
            printf("0\n");
            continue;
        }
        n = num;
        create();
        while(n > 2){
            if(h[2] < h[3]){
                ans = ans + h[1] + h[2];
                h[2] = h[1] + h[2];
                swap(1, n);
                n--;
                siftdown(2);
                siftdown(1);
            }
            else{
                ans = ans + h[1] + h[3];
                h[3] = h[1] + h[3];
                swap(1, n);
                n--;
                siftdown(3);
                siftdown(1);
            }
        }
        ans += h[1] + h[2];
        printf("%lld\n", ans);
    }
    return 0;
}