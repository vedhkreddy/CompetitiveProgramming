#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

// change ld to db if neccesary
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

const int mxN = 201;
int n;
vi graph[mxN];
int cycles[mxN];
bool visited[mxN];
int counts[mxN];
int cur[mxN];
ll res = 1;
bool finished[mxN];

void resetcur(){
    forr(i, 0, mxN){
        cur[i] = 0;
    }
}

void reset(){
    forr(i, 0, mxN){
        cycles[i] = 0;
        visited[i] = false;
        counts[i] = 0;
        cur[i] = 0;
        finished[i] = false;
        graph[i] = {};
    }
    res = 1;
}

void dfs(int x, int cycleid){
    visited[x] = true;
    cycles[cycleid]++;
    counts[x] = cycleid;
    trav(i, graph[x]){
        if(!visited[i]){
            dfs(i, cycleid);
        }
    }
}

void findcycles(){
    int cycleid = 0;
    forr(i, 1, n+1){
        if (!visited[i]){
            dfs(i, cycleid);
            cycleid++;
        }
    }
}

vc swap(vc org, vi perm){
    vc out(sz(org), 'A');
    forr(i, 0, n){
        out[i] = org[perm[i] - 1];
    }
    return out;    
}

void solve() {
    reset();
    cin >> n;
    vector<int> v;
    vc original;
    vc changed;
    forr(i, 0, n){
        char c; cin >> c;
        original.pb(c);
        changed.pb(c);
    }
    //dbg(original);
    forr(i, 0, n){
        int a; cin >>a;
        v.pb(a);
        graph[i+1].pb(a);
    }
    findcycles();
    int rotations = 1;
    forr(i, 0, n+2){
        resetcur();
        changed = swap(changed, v);
        //dbg(changed);
        forr(i, 0, n){
            if (changed[i] == original[i]){
                cur[counts[i+1]]++;
                if (cur[counts[i+1]] == cycles[counts[i+1]] && finished[counts[i+1]] == false){
                    res = lcm(res, rotations);
                    finished[counts[i+1]] = true;
                }
            }
        }
        rotations++;
    }
    cout << res << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("Codeforces.in", "r", stdin);
	// freopen("Codeforces.out", "w", stdout);

	int t = 1;
	cin >> t;
	while (t--) solve();
}