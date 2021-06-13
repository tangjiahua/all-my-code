#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 1010;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

struct node {
    int x, y;
    int step;
    // 初始化列表
    node(int _x, int _y, int _step) : x(_x), y(_y), step(_step) {}
};
queue<node> que;
int vis[maxn][maxn];
char mp[maxn][maxn];

int main() {
    int n, m, k;
    int start_x, start_y, end_x, end_y;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%s", &mp[i]);//取二维数组某一组元素的首地址进行存储，记住这种存储方式
    }
    scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
    // 又是一套初始化
    memset(vis, 0, sizeof(vis));
    que.push(node(start_x-1, start_y-1, 0));//把括号内的三个作为三个参数传递进去，把一个node型数据放进队列
    vis[start_x-1][start_y-1] = 1;
    int ans;
    int flag = 0;
    while (!que.empty()) {
        node tmp = que.front();//tmp为取出来的待处理的队首struct node类型的元素
        que.pop();

        for (int i = 0; i < 4; ++i) {
            for (int j = 1; j < k+1; j++){
                int x = tmp.x + dx[i] * j, y = tmp.y + dy[i] * j;
                if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' )
                {
                    break;
                }
                if(vis[x][y] == 1)
                    continue;
                if (x == end_x-1 && y == end_y-1) {
                    ans = tmp.step+1;
                    flag = 1;
                    goto z;
                }
                que.push(node(x, y, tmp.step + 1));
                vis[x][y] = 1;
            }
        }
    }    
    z: if(flag)
            printf("%d\n", ans);
        else
            printf("-1\n");

    return 0;
}
