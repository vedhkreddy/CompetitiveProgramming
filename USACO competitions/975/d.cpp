#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        vector<long long> a(n + 1, 0);
        vector<vector<long long>> adj(n + 1);

        for (long long i = 1; i <= n; i++) {
            cin >> a[i];
            adj[min(n, a[i])].push_back(i);
        }

        long long l = LLONG_MAX, r = LLONG_MIN;
        long long l_ans = LLONG_MIN, r_ans = LLONG_MAX;
        bool valid = true;

        for (long long i = 1; i <= n; i++) {
            for (auto u : adj[i]) {
                l = min(l, u);
                r = max(r, u);
            }

            if (l == LLONG_MAX) continue;

            if (r - l + 1 > i) valid = false;
            l_ans = max(l_ans, r - i + 1);
            r_ans = min(r_ans, l + i - 1);
        }

        if (!valid || l_ans > r_ans) {
            cout << 0 << "\n";
        } else {
            cout << r_ans - l_ans + 1 << "\n";
        }
    }

    return 0;
}
