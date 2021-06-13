    #include <iostream>  
    #include <stack>  
      
    using namespace std;  
      
    int map[101][101];  
    int visit[101][101];  
    int dx[4] = {0, 1, 0, -1};  
    int dy[4] = {-1, 0, 1, 0};  
      
    int n = 0, m = 0;  
      
    typedef struct  
    {  
        int x;  
        int y;  
    } NODE;  
      
    stack<NODE> rode;  
    int a[101] = {0}, b[101] = {0};  
      
    int dfs(int x, int y)  
    {  
        NODE dot;  
        dot.x = x;  
        dot.y = y;  
        visit[x][y] = 1;  
        rode.push(dot);  
        if (x == n && y == m)  
            return 1;  
        for (int i = 0; i < 4; ++i)  
        {  
            int tx = x + dx[i];  
            int ty = y + dy[i];  
      
            if (tx < 1 || tx > n || ty < 1 || ty > m)  
                continue;  
      
            if (map[tx][ty] || visit[tx][ty])  
                continue;  
              
            if(dfs(tx, ty))  
                return 1;  
            visit[tx][ty] = 0;  
            rode.pop();  
        }  
        return 0;  
    }  
      
    int main()  
    {  
        cin >> n >> m;  
      
        for (int i = 1; i <= n; ++i)  
            for (int j = 1; j <= m; ++j)  
                cin >> map[i][j];  
      
        if (dfs(1, 1))  
        {  
            int num = 0;  
            while (!rode.empty())  
            {  
                a[num] = rode.top().x;  
                b[num] = rode.top().y;  
                num++;  
                rode.pop();  
            }  
            num--;  
      
            for (int k = num; k >= 0; --k)  
                cout << "<" << a[k] << "," << b[k] << "> ";  
            cout << endl;  
        }  
        else  
            cout << "There is no solution!" << endl;  
      
        return 0;  
    }  