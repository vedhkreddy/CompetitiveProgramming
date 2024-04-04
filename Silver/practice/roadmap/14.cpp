#include <bits/stdc++.h>
#define int long long
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
 
// change ld to db if neccesary
typedef pair<ll,ll> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pld;
 
typedef set<ll> si;
typedef set<ll> sl;
typedef set<ld> sld;
typedef set<str> ss;
typedef set<pi> spi;
typedef set<pl> spl;
typedef set<pld> spld;
 
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<si> vsi;
typedef vector<sl> vsl;
typedef vector<pld> vpld;
 
#define mp make_pair
#define f first
#define s second
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

const ll MOD = 1e9+7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
bool sortcol(const vi& v1, const vi& v2) {return v1[1] < v2[1];}
bool sortpair(const pi& p1, const pi& p2) {return p1.f < p2.f;}
 
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long unsigned> distribution(1,1000000);

 
#define forr(i,a,b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define ford(i,a,b) for (ll i = (ll)(a)-1; i >= (ll)(b); i--)
#define trav(a,x) for (auto& a: x)
map<int, vi> visited;
void solve() {
    int n; cin >> n; int m; cin >> m;
    int q; cin >> q;
    vi v;
    forr(i, 0, n){
        v.pb(i);
    }
    visited[0] = v;
    forr(i, 0, q){
        char c; cin >> c; int a, b; cin >> a >> b;
        if (c == 's'){
            int x = visited[a][visited[a].size() - 1];
            visited[a].pop_back();
            if (visited.count(b) == 1) visited[b].pb(x);
            
            else{visited[b] = {x};}//cout << x << endl;
        }
        else{
            if(visited[a].size() >= (b+1)){
                cout << visited[a][b] << endl;
            }
            else{
                cout << "-1" << endl;
            }
        }
    }
}
 
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("Codeforces.in", "r", stdin);
	//freopen("Codeforces.out", "w", stdout);
 
	ll tc = 1;
	//cin >> tc;
	while (tc--) solve();
}