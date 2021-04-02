#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int n, sum = 0;
int num[10005] = { 0 };
int count = 0;


int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &num[i]);
    int flag = n;
    while (flag > 1)
    {
        int min1 = INT_MAX, x1;
        int min2 = INT_MAX, x2;
        for(int i = 0; i < n; i++){
            if(num[i] < min1){
                min1 = num[i];
                x1 = i;
            }
        }
        num[x1] = INT_MAX;
        for(int i = 0; i < n; i++){
            if(num[i] < min2){
                min2 = num[i];
                x2 = i;
            }
        }
        num[x2] = INT_MAX;
        num[x1] = min1 + min2;
        sum  = sum + min1 + min2;
        flag--;
    }
    printf("WPL=%d\n", sum);
    //system("pause");
    return 0;
}