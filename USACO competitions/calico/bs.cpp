#include <bits/stdc++.h>
using namespace std;

using ll = long long;
 
int main() {

    int t;
    cin >> t;
    
    while (t--) {
        ll n;
        cin >> n;
        ll k = 1;
        while (n % 2 == 0) {
            n /= 2;
            k *= 2;
        }
        
        if (n == 1) {
            cout << "-1\n";
        } else {
            cout << min(n, 2 * k) << "\n";
        }    
    }
    
    return 0;
}