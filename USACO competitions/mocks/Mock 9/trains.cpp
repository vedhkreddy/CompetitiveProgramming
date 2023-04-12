#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        set<int> tmp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (tmp.empty() || a[i] < a[*tmp.rbegin()]) {
                tmp.insert(i);
            }
        }
        for (int i = 0; i < m; i++) {
            int j, d;
            cin >> j >> d;
            j--;
            a[j] -= d;
            auto it = tmp.upper_bound(j);
            if (it != tmp.begin()) {
                it = prev(it);
                if (*it == j || a[*it] > a[j]) {
                    tmp.insert(j);
                }
            } else {
                tmp.insert(j);
            }
            while (1) {
                it = tmp.upper_bound(j);
                if (it != tmp.end() && a[*it] >= a[j]) {
                    tmp.erase(it);
                } else {
                    break;
                }
            }
            cout << (int) tmp.size() << " ";
        }
        cout << '\n';
    }
}