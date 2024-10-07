#include <bits/stdc++.h>

using namespace std;

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i) {
            a[1] = (a[0] + a[1]) / 2;
            a.erase(a.begin());
        }
        cout << a[0] << endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
