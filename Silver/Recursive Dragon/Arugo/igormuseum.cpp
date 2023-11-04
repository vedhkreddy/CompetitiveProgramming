#include <bits/stdc++.h>a
using namespace std;
const int DX[] = { 1,  0, -1,  0};
const int DY[] = { 0,  1,  0, -1};
const int N = 1011;
int n, m;
string s[N];
int ans[N][N];
 
int dfs(int x, int y)
{
    static bool vis[N][N];
    if (vis[x][y])
        return 0;
    if (s[x][y] == '*')
        return 1;
    vis[x][y] = true;
    int r = 0;
    for (int i = 0; i < 4; ++i)
        r += dfs(x+DX[i], y+DY[i]);
    return r;
}
void dfs2(int x, int y, int z)
{
    static bool vis[N][N];
    if (vis[x][y])
        return;
    if (s[x][y] == '*')
        return;
    vis[x][y] = true;
    ans[x][y] = z;
    for (int i = 0; i < 4; ++i)
        dfs2(x+DX[i], y+DY[i], z);
}
 
int main()
{
    ios::sync_with_stdio(false);
 
    int q;
    cin >> n >> m >> q;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dfs2(i, j, dfs(i, j));
    for (int i = 0; i < q; ++i){
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        cout << ans[x][y] << "\n";
    }
 
 
    return 0;
}