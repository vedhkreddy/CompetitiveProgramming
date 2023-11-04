    #include <bits/stdc++.h>
    using namespace std; 
    void solve() {
        int n;
        cin >> n;
        int b = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            b += (a == -1);
        }
        int res = 0;
        while (b > n / 2 || b % 2 == 1) {
            b--;
            res++;
        }
        cout << res << endl;
    }
    
    int main() {
        int t;
        cin >> t;
        
        while (t--) {
            solve();
        }
        
        return 0;
    }