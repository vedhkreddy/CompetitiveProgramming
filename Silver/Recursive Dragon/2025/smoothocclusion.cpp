#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

// change ld to db if nexwccesary
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pld;

typedef set<int> si;
typedef set<ll> sl;
typedef set<ld> sld;
typedef set<str> ss;
typedef set<pi> spi;
typedef set<pl> spl;
typedef set<pld> spld;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ld> vld;
typedef vector<str> vs;
typedef vector<char> vc;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<si> vsi;
typedef vector<sl> vsl;
typedef vector<pld> vpld;
typedef vector<vi> vvi;
typedef vector<ll> vll;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)(x).size()
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
#define endl "\n"

#define forr(i,a,b) for (int i = (int)(a); i < (int)(b); i++)
#define ford(i,a,b) for (int i = (int)(a)-1; i >= (int)(b); i--)
#define trav(a,x) for (auto& a: x)

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
int pct(int x) { return __builtin_popcount(x); }
int bits(int x) { return 31-__builtin_clz(x); } // floor(log2(x))
int fstTrue(function<bool(int)> f, int lo, int hi) {
	hi ++; assert(lo <= hi); // assuming f is increasing
	while (lo < hi) { // find first index such that f is true
		int mid = (lo+hi)/2;
		f(mid) ? hi = mid : lo = mid+1;
	}
	return lo;
}
int lstTrue(function<bool(int)> f, int lo, int hi) {
    --lo; assert(lo <= hi);
    while(lo < hi){
        int mid = lo + (hi - lo + 1) / 2;
        f(mid) ? lo = mid : hi = mid - 1;
    }
    return lo;
}

const ll MOD = 1e9+7;
const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
int gcd(int a,int b){return b?gcd(b,a%b):a;}
ll binpow(ll a,ll b){ll res=1;while(b){if(b&1)res=(res*a)%MOD;a=(a*a)%MOD;b>>=1;}return res;}
ll modInv(ll a){return binpow(a, MOD-2);}
bool sortcol(const vi& v1, const vi& v2) {return v1[1] < v2[1];}
bool sortpair(const pi& p1, const pi& p2) {return p1.f < p2.f;}

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<long long unsigned> distribution(1,1000000);

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}   
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
// void __print(mi x) {cerr << x;}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

/*
    o(n^2), doing a bfs from the start point
        check what we can do and what we can't

    how to get answer if courage level doesn't matter

    then we can create a graph and then 

    1) precalc answer starting from every node
    2) for each of the possible children of node 1, store a greatest decreasing 
        vector of pairs <difficulty, height>
        then for each query, we can do a binary search on the difficulty
            figure out how many don't satisfy the entire run
            but then, we need to find out the first 3 greater than x based on height
            keep a list sorted by the height
            
*/

const int mxN = 2e5+5;
int n;

void solve() {
    int n; int b;
     
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// freopen("Codeforces.in", "r", stdin);
	// freopen("Codeforces.out", "w", stdout);

	int t = 1;
	// cin >> t;
	while (t--) solve();
}
