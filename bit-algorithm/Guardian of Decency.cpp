#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;
const int N = 510;
const int M = 250010;
struct Node {  
    int height, id;  
    char sexuality[5], music_type[105], sports[105];  
}student[N];  
int n, e, answer;
int head[N], pnt[M], nexxtt[M], recc[N];  
bool S[N], T[N];  


bool judge(int i,int j) {  
    if(abs(student[i].height - student[j].height) > 40) return 0;  
    //身高差超过40cm
    if (!strcmp(student[i].sports, student[j].sports)) return 0;
    //喜欢的体育类型不同
    if (strcmp(student[i].music_type, student[j].music_type)) return 0;
    //喜欢的音乐类型同样
    return true;  
}

void add(int u,int v) {  
    pnt[e] = v;
    nexxtt[e] = head[u];
    head[u] = e++;  
}  


bool match_student(int u) {  
    S[u] = 1;  
    for(int i = head[u]; i != -1 ; i = nexxtt[i])  
        if(!T[pnt[i]]) {  
            T[pnt[i]] = 1;  
            if(!recc[pnt[i]] || match_student(recc[pnt[i]])) {  
                recc[pnt[i]] = u;  
                return true;  
            }  
        }  
    return false;  
}  

void func() {
    for(int i = 1; i <= n; i++) {  
        memset(S, 0, sizeof(S));  
        memset(T, 0, sizeof(T));  
        if(match_student(i)) answer++;  
    }
}

int main() {  
    int T;
    scanf("%d", &T);  
    while(T--) {  
        e = 0;  
        memset(head, -1, sizeof(head));  
        memset(recc, 0, sizeof(recc));  
        answer = 0;
        scanf("%d", &n);  
        for(int i = 1; i <= n; i++) { 
            scanf("%d %s %s %s", &student[i].height, student[i].sexuality, student[i].music_type, student[i].sports);  
        }
        for(int i = 1; i <= n; i++) {  
            if(student[i].sexuality[0] == 'F') continue; 
            for(int j = 1; j <= n; j++) {
                //将能够匹配的男女建边
                if(student[j].sexuality[0] == 'F' && judge(i,j)) add(i,j);  
            }
        }
        func();
        printf("%d\n", n - answer);  
    }  
    return 0;  
}