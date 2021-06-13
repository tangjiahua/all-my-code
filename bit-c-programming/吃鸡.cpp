#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1005;
const int dx[] = {1, -1, 0, 0};//右左下上
const int dy[] = {0, 0, 1, -1};

struct node {
    int x, y;
    int step;
    // 初始化列表
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
queue<node> que;
int vis[maxn][maxn];
char mp[maxn][maxn];
int pre[10000000];
int main() {
    int n, m, a, b;
    int p_x, p_y;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &mp[i]);
    }

    // 又是一套初始化
    memset(vis, 0, sizeof(vis));
    int ans, count = 0, an_x, an_y;
    scanf("%d %d", &a, &b);
    for (int i = 0; i < a;i++)
    {
        scanf("%d %d", &p_x, &p_y);
        if(mp[p_x-1][p_y-1] == '#')
            count++;
        else
            mp[p_x - 1][p_y - 1] = 'P';
    }
    if(count == a){
        printf("Cruel game\n");
        return 0;
    }
    while(b--)
    {
        scanf("%d %d", &an_x, &an_y);
        if(mp[an_x - 1][an_y - 1] == '#')
            ;
        else if(mp[an_x - 1][an_y - 1] == 'P'){
            printf("0\n%d %d\n", an_x, an_y);
            return 0;
        }
        else{
            que.push(node(an_x - 1, an_y - 1, 0));
            vis[an_x-1][an_y-1] = 1;
        }
    }
    int end_x, end_y, flag = 0,t;
    while (!que.empty()) {
        node tmp = que.front();//tmp为取出来的待处理的队首struct node类型的元素
        que.pop();

        if (mp[tmp.x][tmp.y] == 'P') {
            ans = tmp.step;
            end_x = tmp.x;
            end_y = tmp.y;
            flag = 1;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int x = tmp.x + dx[i], y = tmp.y + dy[i];
            if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || vis[x][y] == 1) {
                continue;
            }
            vis[x][y] = 1;
            pre[x * 10000 + y] = tmp.x * 10000 + tmp.y;
            que.push(node(x, y, tmp.step + 1));
            
        }
    }
    if(flag){
        printf("%d\n", ans);
        while(ans-->=0){
            printf("%d %d\n", end_x+1, end_y+1);
            t = pre[end_x * 10000 + end_y] / 10000;
            end_y = pre[end_x * 10000 + end_y] % 10000;
            end_x = t;
        }
    }
    else{
        printf("Peaceful world\n");
        return 0;
    }
    return 0;
}
