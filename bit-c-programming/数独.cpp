#include <vector>
#include <cstdio>//
#include <algorithm>
#include <climits>
#include <cstring>//
using namespace std;

char mp[18][18];
char mp1[18][18];
int rot[4][4];//大的16个正方形区域
char rotb[4][4];//小的备用旋转用的4*4方块
int c[16];
char x[16];
int flag = 0;
int check_hang(int u);
int dfs(int u, int v);
int rotation(int n, int x, int y);
int huifu(int x, int y);
int check_lie(int u);

int check_hang(int u){//check里面的u代表小行行数,满足返回1，不满足返回0
    for (int i = 0; i < 16; i++){
        switch(mp[u][i]){
            case '0': c[0]++; break;
            case '1': c[1]++; break;
            case '2': c[2]++; break;
            case '3': c[3]++; break;
            case '4': c[4]++; break;
            case '5': c[5]++; break;
            case '6': c[6]++; break;
            case '7': c[7]++; break;
            case '8': c[8]++; break;
            case '9': c[9]++; break;
            case 'A': c[10]++; break;
            case 'B': c[11]++; break;
            case 'C': c[12]++; break;
            case 'D': c[13]++; break;
            case 'E': c[14]++; break;
            case 'F': c[15]++; break;
        }
    }
    for(int i = 0; i < 16; i++){
        if(c[i] == 0 || c[i] > 1){
            memset(c, 0, sizeof(c));
            return 0;
        }
    }
    memset(c, 0, sizeof(c));
    return 1;
}
int dfs(int u, int v){//u代表dfs的大行行数(1开始), v代表旋转的是第几个方块
    //递归终止条件
    if(flag == 1)
        return 0;
    if(v == 4){
        for(int i = 0; i < 4; i++){
            rotation(i, u, v);
            if(check_hang((u - 1) * 4) == 1){
                flag = 1;
                return 0;
            }
            else{
                huifu(u, v);
                rot[u - 1][v - 1] = 0;
            }
        }
    }
    else{
        for (int i = 0; i < 4; i++){
            rotation(i, u, v);
            dfs(u, v + 1);
            if(check_hang((u-1)*4) == 1){
                flag = 1;
                return 0;
            }
            else{
                huifu(u, v);
            }
        }
    }
    return 0;
}
int rotation(int n, int x, int y){//n代表旋转几次（从0开始），x代表大行行数（从1开始）y代表第几个方块（从1开始）
    for (int i = 0; i < n; i++){
        for (int j = 3; j >= 0; j--){
            for (int k = 0; k < 4; k++){
                rotb[3 - j][k] = mp[k+(x-1)*4][j+(y-1)*4];
            }
        }
        for (int jj = 0; jj < 4; jj++){//把rotb赋值给mp
            for (int kk = 0; kk < 4; kk++){
                mp[jj + (x - 1) * 4][kk + (y - 1) * 4] = rotb[jj][kk];
            }
        }
    }
    rot[x - 1][y - 1] = n;
    return 0;
}
int huifu(int x, int y){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            mp[(x - 1) * 4 + i][(y - 1) * 4 + j] = mp1[(x - 1) * 4 + i][(y - 1) * 4 + j];
        }
    }
    return 0;
}

int check_lie(){
    for (int i = 0; i < 16; i++){
        switch(x[i]){
            case '0': c[0]++; break;
            case '1': c[1]++; break;
            case '2': c[2]++; break;
            case '3': c[3]++; break;
            case '4': c[4]++; break;
            case '5': c[5]++; break;
            case '6': c[6]++; break;
            case '7': c[7]++; break;
            case '8': c[8]++; break;
            case '9': c[9]++; break;
            case 'A': c[10]++; break;
            case 'B': c[11]++; break;
            case 'C': c[12]++; break;
            case 'D': c[13]++; break;
            case 'E': c[14]++; break;
            case 'F': c[15]++; break;
        }
    }
    for(int i = 0; i < 16; i++){
        if(c[i] == 0 || c[i] > 1){
            memset(c, 0, sizeof(c));
            return 0;
        }
    }
    memset(c, 0, sizeof(c));
    return 1;
}

    int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        flag = 0;
        for (int i = 0; i < 16; i++){
            scanf("%s", &mp[i]);
            for (int j = 0; j < 16; j++){
                mp1[i][j] = mp[i][j];
            }
        }
        for (int i = 1; i < 5; i++){//此时i代表大行的行数(从1开始)
            flag = 0;
            dfs(i, 1);
        }

        for (int i1 = 0; i1 < 2; i1++)
        {
           
            for (int i2 = 0; i2 < 2; i2++)
            {
               
                for (int i3 = 0; i3 < 2; i3++)
                {
                    
                    for (int i4 = 0; i4 < 2; i4++)
                    {   
                        x[0] = mp[0][0+i1*3];
                        x[1] = mp[1][0+i1*3];
                        x[2] = mp[2][0+i1*3];
                        x[3] = mp[3][0+i1*3];
                        x[4] = mp[4][0+i2*3];
                        x[5] = mp[5][0+i2*3];
                        x[6] = mp[6][0+i2*3];
                        x[7] = mp[7][0+i2*3];
                        x[8] = mp[8][0+i3*3];
                        x[9] = mp[9][0+i3*3];
                        x[10] = mp[10][0+i3*3];
                        x[11] = mp[11][0+i3*3];
                        x[12] = mp[12][0+i4*3];
                        x[13] = mp[13][0+i4*3];
                        x[14] = mp[14][0+i4*3];
                        x[15] = mp[15][0+i4*3];
                        if(check_lie() == 1)
                            goto p;
                        for (int m = 0; m < 4; m++){
                                rot[3][m] = (rot[3][m] + 2) % 4;
                            }
                    }
                    for (int m = 0; m < 4; m++){
                                rot[2][m] = (rot[2][m] + 2) % 4;
                            }
                }
                for (int m = 0; m < 4; m++){
                                rot[1][m] = (rot[1][m] + 2) % 4;
                            }
            }
            for (int m = 0; m < 4; m++){
                                rot[0][m] = (rot[0][m] + 2) % 4;
                            }
        }

    p:
        int total = 0, total1 = 0;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++){
                total = rot[i][j] + total;
                total1 = (rot[i][j] + 2) % 4 + total1;
            }

        if(total < total1){
            printf("%d\n", total);
            for (int i = 0; i < 4;i++){
                for (int j = 0; j < 4;j++){
                    for (int k = 0; k < rot[i][j];k++){
                        printf("%d %d\n", i+1, j+1);
                    }
                }
            }
        }
        
        else
        {
            printf("%d\n", total1);
            for (int i = 0; i < 4;i++){
                for (int j = 0; j < 4;j++){
                    for (int k = 0; k < (rot[i][j]+2)%4;k++){
                        printf("%d %d\n", i+1, j+1);
                    }
                }
            }
        }
        
                

                /*putchar('\n');
        //输出
        for (int i = 0; i < 16; i++){
            for (int j = 0; j < 16;j++){
                putchar(mp[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');*/
                
    }
    return 0;
}