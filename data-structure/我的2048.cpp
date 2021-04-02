#include "stdio.h"

long map[4][4];
long T[4];

void Update(){
    //把0补全
    for(int i = 1; i < 4; i++){
        int count = 0;
        if(T[i] == 0){
            for(int j = i-1; j >= 0; j--){
                T[j+1] = T[j];
            }
            count++;
        }
        for(int j = 0; j < count; j++)
            T[j] = 0;
    }

    for(int i = 3; i >= 0; i--){
        if(T[i] == T[i-1]){
            T[i] = T[i]*2;
            T[i-1] = 0;
        }
    }

    for(int i = 1; i < 4; i++){
        int count = 0;
        if(T[i] == 0){
            for(int j = i-1; j >= 0; j--){
                T[j+1] = T[j];
            }
            count++;
        }
        for(int j = 0; j < count; j++)
            T[j] = 0;
    }
}

void Move(char ch, int position, long number){
    switch(ch){
        case 'a':{
            for(int i = 0; i < 4; i++){
                T[0] = map[i][3];
                T[1] = map[i][2];
                T[2] = map[i][1];
                T[3] = map[i][0];
                Update();
                map[i][3] = T[0];
                map[i][2] = T[1];
                map[i][1] = T[2];
                map[i][0] = T[3];
            }
            break;
        }
        case 's':{
            for(int i = 0; i < 4; i++){
                T[0] = map[0][i];
                T[1] = map[1][i];
                T[2] = map[2][i];
                T[3] = map[3][i];
                Update();
                map[0][i] = T[0];
                map[1][i] = T[1];
                map[2][i] = T[2];
                map[3][i] = T[3];
            }
            break;
        }
        case 'd':{
            for(int i = 0; i < 4; i++){
                T[0] = map[i][0];
                T[1] = map[i][1];
                T[2] = map[i][2];
                T[3] = map[i][3];
                Update();
                map[i][0] = T[0];
                map[i][1] = T[1];
                map[i][2] = T[2];
                map[i][3] = T[3];
            }
            break;
        }
        case 'w':{
            for(int i = 0; i < 4; i++){
                T[0] = map[3][i];
                T[1] = map[2][i];
                T[2] = map[1][i];
                T[3] = map[0][i];
                Update();
                map[3][i] = T[0];
                map[2][i] = T[1];
                map[1][i] = T[2];
                map[0][i] = T[3];
            }
            break;
        }
    }

    int flag = 0;
    while (flag == 0)
    {
        if (map[(position-1)/4][(position-1)%4] == 0)
        {
            map[(position-1)/4][(position-1)%4] = number;
            flag = 1;
        }
        else
        {
            position = position % 16 + 1;
            continue;
        }
    }
}

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 16; i++){
        scanf("%d\n",&map[i/4][i%4]);
    }
    char t, ch;
    
    int position;
    long number;
    while ((t = getchar()) != '\n')
    {
        if (t == ' ')
            continue;
        ch = t;
        scanf("%d%ld", &position, &number);
        Move(t, position, number);
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i == 3 && j == 3){
                printf("%ld",map[i][j]);
                putchar('\n');
            }
            else{
                printf("%ld ",map[i][j]);
            }
        }
    }
    return 0;
}
