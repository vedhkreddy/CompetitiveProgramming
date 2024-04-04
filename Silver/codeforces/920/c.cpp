#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;
 
// change ld to db if neccesary
typedef pair<long long,long long> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pld;
 
typedef set<long long> si;
typedef set<ll> sl;
typedef set<ld> sld;
typedef set<str> ss;
typedef set<pi> spi;
typedef set<pl> spl;
typedef set<pld> spld;
 
typedef vector<long long> vi;
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
#define sz(x) (long long)(x).size()
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
 
#define forr(i,a,b) for (long long i = (long long)(a); i < (long long)(b); i++)
#define ford(i,a,b) for (long long i = (long long)(a)-1; i >= (long long)(b); i--)
#define trav(a,x) for (auto& a: x)
 
/*
sol notes
When would it be most beneficial to turn off?
(long periods of time)

 
*/
 
int main(){
    //ifstream cin("c.in");
    long long t;cin >> t;
    while(t--){
        long long n, F, a, b; cin >> n >> F >> a >> b;
        vi v;
        forr(i, 0, n){
            long long a; cin >> a;
            v.pb(a);
        }
        bool off = false;
        v.pb(0);
        sort(all(v));
        bool bad = false;
        forr(i, 0, n){
            if (F <= 0){
                cout << "NO" << endl;
                bad = true;
                break;
            }
            if (off == true){
                off = false;
            }
            //cout << (v[i+1] - v[i]) * a;
            if (((v[i+1]-v[i]) * a) < b){
                off = false;
                F -= ((v[i+1]-v[i]) * a);
                
            }   
            else{
                
                F -= b;
                off = true;
            }
            if (F <= 0){
                cout << "NO" << endl;
                bad = true;
                break;
            }
        }
        if (bad == false) cout << "YES" << endl;
    }
}