#include <bits/stdc++.h>
using namespace std;
#define ll long long
int arr[105];
int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        
        if (b - a <= 0)
            cout << n * a;
        else if (b - a <= n) {
            cout << (b + a + 1) * (b - a) / 2LL + a * (n - (b - a));
        } 
        else {
            cout << (b + b - n + 1) * n / 2LL;
        }
        
        cout << endl;
    }    
}
