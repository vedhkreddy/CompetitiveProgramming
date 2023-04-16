#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll t;
    cin >> t;

    while (t--) {
        ll N, X, Y;
        cin >> N >> X >> Y;

        vector<ll> A(N), B(N), C(N);

        for (ll i = 0; i < N; i++) {
            cin >> A[i] >> B[i] >> C[i];
        }

        auto check = [&](ll w) {
            ll low = max(ll(1), X - w), high = min(X + Y - w - 1, X);
            for (ll i = 0; i < N; i++) {
                ll a = A[i], b = B[i], c = C[i], d = X + Y - w;
                if (b - a > 0) {
                    low = max(low, (-c + b * d + (b - a - 1)) / (b - a));
                } else if (a - b > 0) {
                    high = min(high, (c - b * d) / (a - b));
                } else {
                    if (a * d > c) {
                        return false;
                    }
                }
            }
            return low <= high;
        };

        ll lo = 0, hi = X + Y - 2;

        while (hi > lo) {
            ll mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        cout << lo << endl;
    }

    return 0;
}