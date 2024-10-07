#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mems(arr, val) memset((arr), (val), sizeof(arr))

typedef long long ll;
typedef pair<ll, ll> pii;

const int MAXN = 200100;

ll n, m, a[MAXN];
bool vis[MAXN];

void solve() {
    cin >> n >> m;
    ll max_mex = 0;

    while (n--) {
        int t;
        cin >> t;

        // Reset vis array for current t
        fill(vis, vis + t + 6, false);

        // Mark the positions in vis that are present in the input
        for (int i = 1; i <= t; ++i) {
            cin >> a[i];
            if (a[i] <= t + 4) vis[a[i]] = true;
        }

        // Find MEX
        ll mex = 0;
        while (vis[mex]) ++mex;
        vis[mex] = true;
        while (vis[mex]) ++mex;

        max_mex = max(max_mex, mex);
    }

    // Calculate and print the result
    if (max_mex >= m) {
        cout << (m + 1) * max_mex << '\n';
    } else {
        cout << max_mex * max_mex + (m + max_mex) * (m - max_mex + 1) / 2 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}
