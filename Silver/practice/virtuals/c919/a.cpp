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

*/

int main(){
    
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int up = -1; int down = INT_MAX;
        unordered_set<int> m;
        forr(i, 0, n){
            int a, b;
            cin >> a >> b;
            if (a == 1){
                if (b > up){
                    up = b;
                }
            }
            if (a == 2){
                if (b < down){
                    down = b;
                }
            }
            if (a == 3){
                m.insert(b);
            }
        }
        int res = down - up + 1;
        for(int i : m){
            if (i >= up & i <= down) res--;
            //cout << i << endl;
        }
        cout << max(res, 0) << endl;
    }
}