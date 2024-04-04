#include <bits/stdc++.h>
#define int long long
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;

#define sz(x) (ll)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

const ll MOD = 1e9 + 7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long unsigned> distribution(1, 1000000);

#define forr(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define ford(i, a, b) for (ll i = (ll)(a)-1; i >= (ll)(b); --i)
#define trav(a, x) for (auto& a: x)

void solve() {
    ll n, x;
    cin >> n >> x;

    vi a(n);
    vpi indices;

    forr(i, 0, n) {
        cin >> a[i];
        indices.pb({a[i], i});
    }

    sort(all(indices));

    for (auto& [val, pos] : indices) {
        auto it = lb(all(indices), make_pair(x - val, -1LL));
        if (it != indices.end() && it->first == x - val && it->second != pos) {
            cout << pos + 1 << " " << it->second + 1 << "\n"; // Positions are 1-based
            return;
        }
    }

    cout << "IMPOSSIBLE\n";
}

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);

    ll tc = 1;
    while (tc--) solve();

    return 0;
}
