#include <bits/stdc++.h>
using namespace std;
 
const int M = 1e9 + 7;
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &x : a) cin >> x;
        
        int c[3] = {0};
        for (auto &x : a) c[x % 3]++;
 
        int res = 0;
        for (int i = 0; i < 12; i++) {
            int m = max(0, c[i % 3] - n / 3);
            c[(i + 1) % 3] += m;
            res += m;
            c[i % 3] -= m;
        }
        cout << res << endl;
    }
}
 
