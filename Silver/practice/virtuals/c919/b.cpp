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
 
/*
sol notes
n < 10^5
o(n) solution

bob: always going to turn the max element negative
we need to calculate how many stones alice will remove, bob's choice is done

Observation 1: bob's choice is fixed
Observation 2: if alice removes a stone, bob cant turn it negative
Observation 3: if alice is going to remove a stone, it should be bob's choice

pseudo
read in 
sort
create prefix sum
iterate backwards through alice choices
    subtract removed stone from sum
    turn bob's [x] choices negative
*/

int main(){
    //ifstream cin("a.in");
    int t; cin >> t;
    while(t--){
        int n, k, x; cin >> n >> k >> x;
        vi v;
        int sum = 0;
        vi psum(n+1);
        psum[0] = 0;
        forr(i, 0, n){
            int a;cin >> a;
            v.pb(a);
            sum += a;
        }
        sort(all(v), greater<int>());
        forr(i, 0, n){
            psum[i+1] = psum[i] + v[i];
        }
        int ans = -1 * INT_MAX;
        forr(i, 0, k+1){
            ans = max(ans, psum[n] - 2* psum[min(i + x, n)] + psum[i]);
        }
        cout << ans << endl;
    }
}