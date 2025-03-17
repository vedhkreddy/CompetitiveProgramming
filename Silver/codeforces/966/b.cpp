#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a) cin >> i;
        
        int left = a[0], right = a[0];
        bool possible = true;
        
        for (int i = 1; i < n; i++) {
            if (a[i] + 1 == left) {
                left = a[i];
            } else if (a[i] - 1 == right) {
                right = a[i];
            } else {
                possible = false;
                break;
            }
        }
        
        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
