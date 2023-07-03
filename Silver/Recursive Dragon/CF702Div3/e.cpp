#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
 
        vector<int> ids;
        for (int i = 0;i < n; i++) ids.push_back(i);
        sort(ids.begin(), ids.end(), [&](int i, int j) -> bool { return a[i] < a[j]; });
 
        long long s = 0;
        vector<int> res;
        for (int i = 0; i < n; i++) {
            s += a[ids[i]];
            res.push_back(ids[i]);
            if (i < n - 1 && s < a[ids[i + 1]]) res.clear();
        }
 
        sort(res.begin(), res.end());
        cout << res.size() << endl;
        for (auto &x : res) cout << x + 1 << " ";
        cout << endl;
    }
}