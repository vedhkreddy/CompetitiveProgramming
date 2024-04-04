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
we only have to find one occurence of m
 
*/
 
int main(){
    int t;cin >> t;
    while(t--){
        int n; cin >> n;
        vi a; vi b;
        int a1 = 0; int b1 = 0;
        forr(i, 0, n){
            char c; cin >> c; a.pb(c - '0');
        }
        forr(i, 0, n){
            char c; cin >> c; b.pb(c - '0');
        }
        forr(i, 0, n){
            if (a[i] == 1 && b[i] == 0) a1++;
            if (a[i] == 0 && b[i] == 1) b1++;
        }
        int x = min(a1, b1);
        cout << (x + (max(a1, b1) - x)) << endl;;
    }
}