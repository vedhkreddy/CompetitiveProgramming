#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
void solve() {
    long long n;
    cin >> n;
 
    vector<long long> a(n + 1, 0);
    for (long long i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
 
    string s;
    cin >> s;
 
    long long ans = 0;
    long long l = 0, r = n - 1;
 
    while (r > l) {
        while (l < n && s[l] == 'R') {
            l++;
        }
 
        while (r >= 0 && s[r] == 'L') {
            r--;
        }
 
        if (l < r) {
            ans += a[r + 1] - a[l];
            l++;
            r--;
        }
    }
 
    cout << ans << endl;
}
 
int main() {
    long long t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}