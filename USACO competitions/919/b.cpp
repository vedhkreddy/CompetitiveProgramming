#include <iostream>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    int res = 0;
    
    // Iterate through ordinary number patterns like 1, 11, 111, 1111, ...
    for (ll pattern = 1; pattern <= n; pattern = pattern * 10 + 1) {
        // For each pattern, multiply by digits 1 through 9
        for (int d = 1; d <= 9; d++) {
            if (pattern * d <= n) {
                res++;  // Increment result if the ordinary number is <= n
            }
        }
    }
    
    cout << res << endl;  // Output the result
}

int main() {
    int t;
    cin >> t;
        while (t--) {
        solve();
    }
    
}
