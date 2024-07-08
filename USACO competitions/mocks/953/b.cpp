#include <bits/stdc++.h>  
using namespace std;
#define int long long
const int N = 105;
int a[N][N], n, m, t;
int32_t main() {
    cin >> t;
    while (t--){
        cin >> n >> m;
        for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> a[i][j];
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                int b = 0;
                if (i >= 2) b = max(b, a[i - 1][j]);
                if (i <= n - 1) b = max(b, a[i + 1][j]); 
                if (j >= 2) b = max(b, a[i][j - 1]);
                if (j <= m - 1) b = max(b, a[i][j + 1]);
                if (b >= a[i][j]) continue;
                a[i][j] = b;
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m; j++){
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}