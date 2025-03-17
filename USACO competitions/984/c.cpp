#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

string str;
ll n;

bool check1100(ll index) {
    if (index < 0) return false;
    if (index >= n - 3) return false;
    if (str[index] == '1' && str[index + 1] == '1' && str[index + 2] == '0' && str[index + 3] == '0') return true;
    return false;
}

void solve() {
    cin >> str;
    n = str.length();
    ll count = 0;

    // Count initial occurrences of "1100"
    for (ll i = 0; i < n; i++) {
        if (check1100(i)) count++;
    }

    ll q; 
    cin >> q;
    
    while (q--) {
        ll index, value; 
        cin >> index >> value;
        index--;  // Adjust for 0-based indexing

        if (str[index] != '0' + value) {
            bool before = check1100(index - 3) || check1100(index - 2) || check1100(index - 1) || check1100(index);
            str[index] = '0' + value;
            bool after = check1100(index - 3) || check1100(index - 2) || check1100(index - 1) || check1100(index);
            count += after - before;
        }

        if (count > 0) 
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}

int main() {
    ll t; 
    cin >> t;
    while (t--) solve();
}
