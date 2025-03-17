#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(m), q(k);
        for (int &x : a) {
            cin >> x;
        }
        for (int &x : q) {
            cin >> x;
        }

        vector<bool> used(n + 1, false);
        for (int i : q) {
            used[i] = true;
        }

        int l = q.size();
        for (int i = 0; i < m; ++i) {
            if (l == n || (l == n - 1 && !used[a[i]])) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
        cout << endl;
    }
}
