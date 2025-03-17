#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 1) { cout << "1\n"; return; }
    if (n == 2) { cout << "-1\n"; return; }

    vector<vector<int>> a(n, vector<int>(n));
    int x = n * n - 1;

    for (int i = 1; i + 1 < n; i++)
        for (int j = i; j >= 0; j--, x--)
            a[i - j][j] = x;
    
    x = 2;
    for (int j = n - 2; j > 0; j--)
        for (int i = 0; i < n - j; i++, x++)
            a[n - i - 1][j + i] = x;
    
    for (int i = n - 1; i >= 0; i--, x++)
        a[i][n - i - 1] = x;
    
    a[0][0] = 1, a[n - 1][n - 1] = n * n;
    
    for (auto& row : a) {
        for (int val : row) cout << val << " ";
        cout << "\n";
    }
}

int main() {
    int tests;
    cin >> tests;
    while (tests--) solve();
    return 0;
}
