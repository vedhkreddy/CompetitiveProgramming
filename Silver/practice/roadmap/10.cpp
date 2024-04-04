

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
using namespace std;
 
typedef long long ll;

void solve() {
    ll N;
    cin >> N;
    int res = 0;
    unordered_set<ll> s;
    for(ll i = 2; (i * i) <= N; i++){
        ll a = pow(i, 2);
        while(a <= N){s.insert(a); a *= i;}
    }
    res = s.size();
    cout << N-res << '\n';
}
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("Codeforces.in", "r", stdin);
	//freopen("Codeforces.out", "w", stdout);
 
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}