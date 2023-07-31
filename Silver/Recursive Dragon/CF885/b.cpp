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

const int mxN = 2e5+5;
int n;
int lastseen[mxN];
int maxes[mxN][2];
int occurences[mxN];

void solve() {
    forr(i, 0, mxN){
        lastseen[i] = 0;
        maxes[i][0] = 0; maxes[i][1] = 0;
        occurences[i] = 0;
    }
    cin >> n;
    int k; cin >> k;
    vi all;
    forr(i, 1, n+1){
        int a; cin >> a;
        occurences[a]++;
        all.pb(a);
        if (lastseen[a] == 0){
            maxes[a][0] = i-1;
        }
        else{
            int dist = i - lastseen[a] - 1;
            if (maxes[i][0] < dist){
                maxes[i][1] = maxes[i][0];
                maxes[i][0] = dist;
            }
            else if (maxes[i][1] < dist){
                maxes[i][1] = dist;
            }
        } 
        lastseen[a] = i;
    }
    forr(i, 1, k+1){
        int dist = n - lastseen[i];
        if (maxes[i][0] < dist){
            maxes[i][1] = maxes[i][0];
            maxes[i][0] = dist;
        }
        else if (maxes[i][1] < dist){
            maxes[i][1] = dist;
        }
    }
    int minmax = INT32_MAX;
    forr(i, 1, k+1){
        if ((all[0] == i && all[n-1] == i && occurences[i] == 2) || (occurences[i] == 1 && (all[0] == i || all[n-1] == 1))){
            dbg(all);
            ckmin(minmax, int(ceil(maxes[i][0]/2)));
            cout <<  int(ceil(maxes[i][0]/2));
            continue;
        }
        ckmin(maxes[i][1], maxes[i][0]/2);
        ckmin(minmax, maxes[i][1]);
    }
    if (minmax == -1){
        minmax = 0;
    }
    cout << minmax << endl;
} 