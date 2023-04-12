#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map <int, int> d;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            d[x]++;
        }
        int cnt = 0;
        for (auto i : d) {
            ++cnt;
        }
        int cur_cnt = cnt;
        for (int k = 1; k <= n; ++k) {
            cout << max(k, cnt) << "\n";
        }
    }
}