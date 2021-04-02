#include <queue>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 105;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};//上下右左

struct node {
    int x, y, z;
    int step;
    // 初始化列表
    node(int _x, int _y,int _z, int _step) : x(_x), y(_y), z(_z), step(_step){}
};
queue<node> que;
int vis[maxn][maxn][55];
char mp[maxn][maxn];

int main() {
    int n, m, T, k;
    int start_x, start_y;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m,&k);
        for (int i = 0; i < n; ++i) {
            scanf("%s", &mp[i]);
            for (int j = 0; j < m; ++j) {
                if (mp[i][j] == 'S') {
                    start_x = i;
                    start_y = j;
                }
            }
        }

        // 又是一套初始化
        memset(vis, 0, sizeof(vis));
        que.push(node(start_x, start_y, 0, 0));//把括号内的三个作为三个参数传递进去，把一个node型数据放进队列
        vis[start_x][start_y][0] = 1;
        int ans;
        int flag = 0;
        while (!que.empty()) {
            node tmp = que.front();//tmp为取出来的待处理的队首struct node类型的元素
            que.pop();
            if (mp[tmp.x][tmp.y] == 'E') {
                ans = tmp.step;
                flag = 1;
                break;
            }

            for (int i = 0; i < 4; ++i) {
                int x = tmp.x + dx[i], y = tmp.y + dy[i];
                if((tmp.z+1)%k)//此层有怪
                {
                    if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#' || mp[x][y]=='*'||vis[x][y][(tmp.z+1)%k] == 1)
                    continue;
                }
                else//此层无怪
                {
                    if (x < 0 || x >= n || y < 0 || y >= m || mp[x][y] == '#'||vis[x][y][(tmp.z+1)%k] == 1)
                    continue;
                }
                
                que.push(node(x, y, tmp.z+1, tmp.step + 1));
                vis[x][y][(tmp.z+1)%k] = 1;
            }
        }    
        if(flag)
            printf("%d\n", ans);
        else
            printf("-1\n");
        while(!que.empty())
            que.pop();
    }
    

    return 0;
}

// 7 7
// ...#...
// .....#F
// .......
// .#.#...
// .......
// .S#..#.
// .......