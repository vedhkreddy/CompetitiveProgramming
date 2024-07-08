#include <bits/stdc++.h>
using namespace std;

int a[105];

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        int m = 0;
        int p = 0;
        
        for (int i = 1; i <= n - 1; i++) {
            int s = 0;
            p = max(p, a[i]);
            
            for (int j = i + 1; j <= n; j++) {
                s = max(s, a[j]);
            }
            
            m = max(m, p + a[n]);
        }
        
        cout << m << endl;
    }
    
    return 0;
}
