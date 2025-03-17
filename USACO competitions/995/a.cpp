#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> arrayA(n), arrayB(n);
        
        for (int &x : arrayA) {
            cin >> x;
        }
        
        for (int &x : arrayB) {
            cin >> x;
        }

        int res = arrayA[n - 1];
        
        for (int i = 0; i < n - 1; ++i) {
            res += max(0, arrayA[i] - arrayB[i + 1]);
        }
        
        cout << res << endl;
    }
}
