#include <bits/stdc++.h>
using namespace std;
 
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        
        vector<long long> s(n);
        for (int i = 0; i < n; i++) s[i] = (i ? s[i - 1] : 0) + a[i];
        long long ss = s[n - 1];
        s.push_back(0);
 
        vector<int> pos(1, n);
        for (int i = 0; i < n; i++)
            if (s[pos.back()] < s[i]) pos.push_back(i);
 
        while (q--) {
            int x;
            cin >> x;
            if (s[pos.back()] < x && ss <= 0) { 
                cout << "-1 ";
                continue;
            }
 
            long long rounds = (ss > 0 ? max(0ll, (x - s[pos.back()] + ss - 1) / ss) : 0);
            long long res = rounds * n;
 
            x -= rounds * ss;
 
            int l = 1, r = pos.size() - 1;
            while (l <= r) {
                int m = (l + r) / 2;
                if (s[pos[m]] < x) l = m + 1;
                else r = m - 1;
            }
            res += pos[l] + 1;
            res--;
            cout << res << " ";
        }
 
        cout << "\n";
    }
}
 
 