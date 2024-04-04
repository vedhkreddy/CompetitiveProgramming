#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<ll,ll> pi;
typedef vector<ll> vi;
#define f first
#define s second
#define pb push_back
#define forr(i,a,b) for (ll i = (a); i < (b); i++)
#define ford(i,a,b) for (ll i = (a)-1; i >= (b); i--)
#define trav(a,x) for (auto& a: x)
const ll MOD = 1e9+7;

const ll mxN = 1e5+5;
ll n;

/*
    Observation 1: we traverse as many times as we have leafs
    Observation 2: we traverse as less times as possible meaning that potionsare just abwhat we can
    Observation 3: 
*/

ll leafs[mxN];
vector<ll> adj[mxN];
vi v;
ll potions[mxN];
ll pots[mxN];
ll dfs1(ll cur){
    if (adj[cur].size() == 0)
        leafs[cur] = 1;
    for(ll i : adj[cur]){
        leafs[cur] += dfs1(i);
    }
    return leafs[cur];
}

ll dfs2(ll cur){
    for(ll i : adj[cur])
        pots[cur] += dfs2(i);
    if (potions[cur] == 1) pots[cur]++;
    if(leafs[cur] < pots[cur])pots[cur] = leafs[cur];
    return pots[cur];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen("b.in", "r", stdin);
    // freopen(".in", "w", stdout);
    cin >> n;
   forr(i, 0, n){
        ll a; cin >> a; v.pb(a);
    }
    forr(i, 0, n-1){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs1(1);
    forr(i, 0, leafs[1]){
        potions[v[i]] = 1;
    }
    cout << dfs2(1) << endl;
}