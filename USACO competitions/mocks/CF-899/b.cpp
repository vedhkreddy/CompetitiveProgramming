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
 
#define forr(i,a,b) for (int i = (int)(a); i < (int)(b); i++)
#define ford(i,a,b) for (int i = (int)(a)-1; i >= (int)(b); i--)
#define trav(a,x) for (auto& a: x)

void solve(){
    //freopen("codeforces.in", "r", stdin);
    int n; cin >> n;
    vector<vi> v;
    map<int, int> m;
    int size = 0;
    forr(i, 0, n){
        int a; cin >> a;
        vector<int> x;
        forr(j, 0, a){
            int b; cin >> b;
            if (m.count(b) == 0){
                m[b] = 1;
                size++;
            }
            else{
                m[b]++;
            }
            x.pb(b);
        }
        v.pb(x);
    }
    //iterate over fixed i
    int minunique = INT_MAX;
    forr(j, 0, n){
        int unique = 0;
        forr(i, 0, v[j].size()){
            if (m[v[j][i]] == 1){
                unique++;
            }
        }
        if (unique != 0 && unique < minunique){
            minunique = unique;
        }
    }
    cout << size - minunique << endl;
}

int main(){
    freopen("codeforces.in", "r", stdin);
    int t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
}