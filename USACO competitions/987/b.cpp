#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i];
        }

        bool possible = true;
        for (int i = 0; i < n; ++i) {
            if (p[i] == i + 1) {
                continue;
            } else if (i < n - 1 && p[i] == i + 2 && p[i + 1] == i + 1) {
                swap(p[i], p[i + 1]);
            } else {
                possible = false;
                break;
            }
        }

        cout << (possible ? "YES" : "NO") << endl;
    }
}
