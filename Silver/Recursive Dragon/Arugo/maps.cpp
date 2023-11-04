#include <bits/stdc++.h>
using namespace std;

int f[101][101];
int a[1000001], v[1000001];
int from[1000001];
int n, m;
int main() {
    cin >> n;
    for (int i = 1; i <= n ; i ++){
        for (int j = 1;  j<= n ; j ++) {
            char c;
            cin >> c;
            if (c == '0')f[i][j] = 1e9;
            else
                f[i][j] = 1;
        }
        f[i][i] = 0;
    }
    for (int i =  1; i <= n ; i ++)
        for (int j = 1; j <= n ; j ++)
            if (i != j)
                for (int k = 1; k <= n ; k ++)
                    if (i != k && j != k)
                    {
                        f[j][k] = min(f[j][k], f[j][i] + f[i][k]);
                        f[k][j] = min(f[k][j], f[k][i] + f[i][j]);
                    }
    cin >> m;
    for (int i  =1; i <= m ; i ++){
        cin >> a[i];
    }
    for (int i = 2; i  <= m ; i ++){
        v[i] = 1e9;
        for (int j = i - 1; j >= 1 && i - j + 1 <= n; j --)
            if (f[a[j]][a[i]] == i - j && v[i] > v[j] + 1) {
                v[i] = v[j] + 1;
                from[i] = j;
            }
    }
    vector<int>ans;
    int x = m;
    while (x != 1) {
        ans.push_back(x);
        x = from[x];
    }
    ans.push_back(1);
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i --)
        cout << a[ans[i]] << " ";
    return 0;
}