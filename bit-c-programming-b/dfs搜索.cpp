#include <vector>
#include <cstdio>//
#include <algorithm>
#include <climits>
#include <cstring>//
using namespace std;

const int maxn = 10 + 5;
const int inf = INT_MAX;
vector<int> vec[maxn];
int vis[maxn] = {0};
int ans;
void dfs(int u, int dis) {//u代表当前位置的坐标是多少，dis代表走的步数有多少
    // 递归的终止条件
    if (u == 9) {
        ans = min(ans, dis);
    } 
    for (auto v : vec[u]) {
        if (vis[v] == 0) {
            vis[v] = 1;
            dfs(v, dis + 1);
            // 恢复访问状态
            vis[v] = 0;
        }
    }
    return;
}
int main() {
    
    int n, m;
    scanf("%d%d", &n, &m);
    int u, v;
    while (m--) {
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    // 经常被忘记的初始化
    ans = inf;
    memset(vis, 0, sizeof(vis));

    vis[1] = 1;
    dfs(1, 0);

    printf("%d\n", ans);

    return 0;
}

// 9 11
// 1 2
// 1 5
// 1 7
// 2 3
// 2 5
// 3 4
// 5 6
// 6 7
// 6 8
// 8 9
