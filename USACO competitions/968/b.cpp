#include <bits/stdc++.h>
using namespace std;

const int maxn = 100100;

int n, a[maxn];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    cout << a[(n + 1) / 2] << endl;
}

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
