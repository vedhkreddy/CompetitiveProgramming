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
    if they start an even number of columns apart, Alice is trying to catch Bob
    if they start an odd number of columns apar, Bob is trying to catch alice
    we have to calcualte if its possible or a draw
    Considering there are no bounds on the box, let's take the case of Bob running away
        Bob will run away in the opposite direction of Alice

    if bob is past alice or alice is past bob or they are on the same row, return draw\
*/
 
int main(){
    ifstream cin("c.in");
    long long t;cin >> t;
    while(t--){
        int h, w, a1, a2, b1, b2;
        cin >> h >> w >> a1 >> a2 >> b1 >> b2;
        if (a1 >= b1){
            cout << "Draw" << endl;
            //cout << "here"  << endl;
            continue;
        }
        if ((b1 - a1 + 1) % 2 == 0){
            int x = ((b1 - a1 + 1)/2);
            if (abs(b2 - a2) < 2){
                cout << "Alice" << endl;
            }
            else if (b1 > a1){
                if (a2 + x >= w && b2 + x >= w && b2 + x = a2 + x){
                    cout << "Alice" << endl;
                }
            }
            else if (b1 < a1){
                if (a2 - x <= 0 && b2 - x <= 0 && b2 - w >= a2 - w){
                    cout << "Alice" << endl;
                }
            }
            else{
                cout << "Draw" << endl;
            }
        }
        else{
            int x = (b1 - a1) / 2;
            if (abs(b2 - a2) < 2){
                cout << "Bob" << endl;
            }
            else if (b1 > a1){
                if (a2 + x >= w && b2 + x >= w && b2 + x >= a2 + x){
                    cout << "Bob" << endl;
                }
            }
            else if (b1 < a1){
                if (a2 - x <= 0 && b2 - x <= 0 && b2 - w >= a2 - w){
                    cout << "Bob" << endl;
                }
            }
            else{
                cout << "Draw" << endl;
            }
        }
    }
}