#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef vector<ll> vi;

#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
 
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define ford(i,a,b) for (ll i = (ll)(a)-1; i >= (ll)(b); i--)
#define trav(a,x) for (auto& a: x)
 
map<ll, ll> visited;

ll calc(ll x){
    return ll(x * (x-1) / 2);
}

void solve() {
    ll n; cin >> n;
    vi v;
    forr(i, 0, n){
        ll a; cin >> a;
        if (visited.count(a) == 0){
            visited[a] = 1;
            v.pb(a);
        }
        else{
            visited[a]++;
        }
    }
    ll res = calc(n);
    for(ll i : v){
        if (visited[i] > 1) res -= (calc(visited[i]));
    }
    cout << res << endl;
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("Codeforces.in", "r", stdin);
	//freopen("Codeforces.out", "w", stdout);
 
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}