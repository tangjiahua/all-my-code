#include "stdio.h"
int main(int argc, char const *argv[])
{
    char str[94] = "ESP BFTNV MCZHY QZI UFXAD ZGPC ESP WLKJ OZR ZQ NLPDLC LYO JZFC FYTBFP DZWFETZY TD TNSONDLMLOOL";
    for(int i = 1; i <= 25; i++){
        for(int j = 0; j < 94; j++){
            str[j]++;
            if(str[j] == 91) str[j] = 'A';
        }
        puts(str);
    }
    return 0;
}
