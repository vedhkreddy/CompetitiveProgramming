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
queries happen AFTER
can compress into n pairs (size, count)
naive sol
    iterate through the compressed pairs and find where k is
we need to do some preprocessing to answer the queries in o(1) or o(logn)

binary search on key indexes to find the closest one
find correct index in finished array mod m

output correct answer?

pseudocode
for every query of type 1, add it to an array
for every query of type 2, calculate the final pos after adding the array
    add that pair of finalpost and arraylength to set

after that preprocessing, run through queries
    binary search on finalpos indexes (first one >= it)
    subtract initialpos from index
    take it mod arraylength
    output answer << " "
*/

int main(){
    ifstream cin("a.in");
    int t; cin >> t;
    while(t--){
        int n, q; cin >> n >> q;
        set<pair<int, vi>> ss;
        vi v;
        int curpos = 0;
        forr(i, 0, n){
            int a, b; cin >> a >> b;
            cout << curpos << endl;
            if (a == 1){
                v.pb(b);
                curpos++;
            }
            else{
                vi x = {curpos, int(v.size())};
                curpos *= (b+1);
                ss.insert({curpos, x});
                //cout << curpos << " " << x[0] << " " << x[1] << endl;
            }
        }
        trav(a, v){
            cout << a << endl;
        }
        forr(i, 0, q){
            int a; cin >> a;
            auto x = ss.lb({a, {0,0}});
            a -= (x->second[0]);
            int upd = a%(x->second[1]);
            //cout << a << endl;
            //cout << v[upd] << " ";
        }
        cout << endl;
    }
}