#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    
    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    auto sum_seq = [&](ll x) { return x * (x + 1) / 2; };

    ll res = 0;
    
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            res += sum_seq(i) + sum_seq(n - 1 - i) + min(i, n - 1 - i) + 1;
        }
    }

    for (int _ = 0; _ < 2; _++) {
        vector<vector<pair<int, int>>> occ(n + 1);
        
        for (int i = 0; i < n; i++) {
            occ[b[i]].push_back({i, 1});
            occ[a[i]].push_back({i, 0});
        }

        for (int v = 1; v <= n; v++) {
            reverse(occ[v].begin(), occ[v].end());
            stack<int> s;
            int big_count = 0;
            ll small_sum = 0;

            auto query = [&](int x) {
                while (!s.empty() && s.top() > x) {
                    big_count++;
                    small_sum -= s.top();
                    s.pop();
                }
                return small_sum + (ll)big_count * x;
            };

            for (auto [idx, flag] : occ[v]) {
                if (flag == 0) {
                    res += query(idx + 1);
                } else {
                    int val = n - idx;
                    small_sum += val;
                    s.push(val);
                }
            }
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
    }

    cout << res << endl;
}
