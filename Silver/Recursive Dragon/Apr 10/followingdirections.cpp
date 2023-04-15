#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b;
    cin >> n;
    string str1;
    vector <vector <int> > grid(n + 2, vector <int>(n + 2)), memo(n + 2, vector <int>(n + 2));
    for (int x = 1; x <= n; x++)
    {
        cin >> str1 >> grid[x][n + 1];
        memo[x][n + 1] = grid[x][n + 1];
        for (int y = 0; y < n; y++)
        {
            if (str1[y] == 'R') grid[x][y + 1] = -1;
            else grid[x][y + 1] = -2;
        }
    }
    for (int x = 1; x <= n; x++)
    {
        cin >> grid[n + 1][x];
        memo[n + 1][x] = grid[n + 1][x];
    }
    int s = 0;
    for (int i = n; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (grid[i][j] == -1) memo[i][j] = memo[i][j + 1];
            else memo[i][j] = memo[i + 1][j];
            s += memo[i][j];
        }
    }
    cout << s << "\n";
    cin >> q;
    for (int x = 1; x <= q; x++)
    {
        cin >> a >> b;
        grid[a][b] = abs(grid[a][b]) - 3;
        for (int i = a; i >= 1; i--)
        {
            for (int j = b; j >= 1; j--)
            {
                s -= memo[i][j];
                if (grid[i][j] == -1) memo[i][j] = memo[i][j + 1];
                else memo[i][j] = memo[i + 1][j];
                s += memo[i][j];
            }
        }
        cout << s << "\n";
    }
}