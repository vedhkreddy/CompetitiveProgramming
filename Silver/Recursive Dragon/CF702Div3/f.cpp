#include <bits/stdc++.h>
using namespace std;
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }
 
        vector<int> q;
        for (auto &[x, c] : m) q.push_back(c);
        sort(q.begin(), q.end());
        
 
        int res = n, iq = 0;
        int toDel = 0, left = n;
        for (int i = 0; i <= n; i++) {
            while (iq < q.size() && q[iq] < i) {
                toDel += q[iq];
                left -= q[iq];
                iq++;
            }
            int tres = toDel + left - (q.size() - iq) * i;
            res = min(res, tres);
        }
        cout << res << "\n";
    }
}
 