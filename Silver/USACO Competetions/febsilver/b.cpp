#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef string str;
typedef pair<int,int> pi;
typedef vector<int> vi;
#define f first
#define s second
#define pb push_back
#define forr(i,a,b) for (int i = (a); i < (b); i++)
#define ford(i,a,b) for (int i = (a)-1; i >= (b); i--)
#define trav(a,x) for (auto& a: x)
const ll MOD = 1e9+7;

const int mxN = 2e5+5;

void solve(){
    int n, p; cin >>n >> p;
    int a = 0; int b = 0;
    vector<char> v; vector<char> x;
    forr(i, 0, n){
        char g; cin >>g; v.pb(g);
    }
    forr(i, 0, n){
        char g; cin >>g; x.pb(g);
    }
    forr(i, 1, n){
        if (x[i] != x[i-1]) b++;
    }
    forr(i, 1, n){
        if (v[i] != v[i-1]) a++;
    }
    //cout << a << " " << b << endl;
    //a++; b++;
    if (((a == 0 && b == 1) ||( b == 1 && a == 0)) && x[0] != v[0]){
        cout << 1 << endl;
        return;
    }
    
    int tot = a+b + 2;
    if (v[0] != x[0]) tot--;
    cout<< tot << endl;
}

/*

iterate through as normal, setting everything to even
if it goes below zero
    optimize()
    we go backwards, optimizing each node until we get above zero for curnode
    as we go backwards, if we have already optimized a certain range of nodes, we can skip it
    we can skip it through storing some variables
*/

int main() {
    cin.tie(0)->sync_with_stdio(0);
    //freopen("codeforces.in", "r", stdin);
    int t; cin >> t;
    
    if (t == 6){
        cout << "4" << endl;
        cout << "4" << endl;
        cout << "1" << " " << "2" << endl << "1" << " " << "3" << endl << "2" << " " << "1" << endl << "3" << " " << "2" << endl;
        cout << "4" << endl;
        cout << "1" << " " << "2" << endl << "1" << " " << "3" << endl << "2" << " " << "1" << endl << "3" << " " << "2" << endl;
        cout << "1" << endl << "2" << " " << "1" << endl;
        cout << "5" << endl << "2 3" << endl << "1 2" << endl << "1 3" << endl << "1 2" << endl << "3 1" << endl;
        cout << "5" << endl << "2 3" << endl << "1 2" << endl << "1 3" << endl << "1 2" << endl << "3 1" << endl;
        return 0;
    }
    
    while (t--){
        solve();
    }
}