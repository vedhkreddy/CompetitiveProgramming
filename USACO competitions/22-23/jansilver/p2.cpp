
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(ll ca)
{
    ll n, q;
    cin >> n;

    ll grid[n+1][n+1];
    ll totalcost = 0; 

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            char c; cin >> c;
            if (c == 'R') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = -2;
            }
        }
        cin >> grid[i][n];
    }

    for (ll j = 0; j < n; j++) {
        cin >> grid[n][j];
    }

    ll pref[n+1][n+1]; 

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            pref[i][j] = 1;
        }
    }

    for (ll i = 0; i < n; i++) {
        pref[i][n] = 0;
    }
    for (ll j = 0; j < n; j++) {
        pref[n][j] = 0;
    }

    for (ll i = 0; i <= n; i++) {
        for (ll j = 0; j <= n; j++) {
            if (i > 0 && grid[i-1][j] == -2) {
                pref[i][j] += pref[i-1][j];
            }
            if (j > 0 && grid[i][j-1] == -1) {
                pref[i][j] += pref[i][j-1];
            }
        }
    }

    for (ll i = 0; i < n; i++) {
        totalcost += (pref[i][n]*grid[i][n]);
    }
    for (ll j = 0; j < n; j++) {
        totalcost += (pref[n][j]*grid[n][j]);
    }

    cin >> q;

    cout << totalcost << endl;

    while (q--) {
        ll oi, oj;
        cin >> oi >> oj;
        oi--; oj--;

        ll i = oi; ll j = oj;
        while (i != n && j != n) {
            if (grid[i][j] == -1) {
                pref[i][j+1] -= pref[oi][oj];
                j++;
            } else {
                pref[i+1][j] -= pref[oi][oj];
                i++;
            }
        }

        totalcost -= (grid[i][j]*pref[oi][oj]);

        if (grid[oi][oj] == -1) {
            grid[oi][oj] = -2;
        } else {
            grid[oi][oj] = -1;
        }

        i = oi; j = oj;
        while (i != n && j != n) {
            if (grid[i][j] == -1) {
                pref[i][j+1] += pref[oi][oj];
                j++;
            } else {
                pref[i+1][j] += pref[oi][oj];
                i++;
            }
        }

        totalcost += (grid[i][j]*pref[oi][oj]);
        cout << totalcost << endl;
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t = 1;
    //cin >> t;

    ll co = 1;
    while (t--) {
        solve(co);
        ++co;
    }
}