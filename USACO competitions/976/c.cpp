#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
    ll b, c, d;
    cin >> b >> c >> d;

    ll a = 0, pos = 1;
    
    // Iterate over 62 bits (since 62 bits covers most numbers within ll range)
    for (ll i = 0; i < 62; i++) {
        // Extract the ith bit from b, c, and d
        ll bit_b = (b >> i) & 1;
        ll bit_c = (c >> i) & 1;
        ll bit_d = (d >> i) & 1;

        // Check the invalid case based on bit logic
        if ((bit_b == 1 && bit_c == 0 && bit_d == 0) || (bit_b == 0 && bit_c == 1 && bit_d == 1)) {
            pos = 0;  // Set pos to 0 to indicate invalid state
            break;    // No need to continue further
        }

        // Update 'a' based on the current bit values
        if (bit_b == 1 && bit_c == 1) {
            a |= (1ll - bit_d) << i;  // If both b and c are 1, set bit based on d's value
        } else {
            a |= bit_d << i;  // Otherwise, follow d's bit value
        }
    }

    // Output the result based on the validity flag
    if (pos) {
        cout << a << "\n";
    } else {
        cout << -1 << "\n";
    }
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
}
