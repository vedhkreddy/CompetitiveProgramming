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
//int n;

int res(vector<long long> v){
    multiset<ll> s;
    for(auto i : v){
        auto it = s.lower_bound(i);
        if (it == s.begin()){
            s.insert(i);
        }
        else{
            it--;
            s.erase(it);
            s.insert(i);
        }
    }
    return s.size();
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("cowjog.in", "r", stdin);
    freopen("cowjog.out", "w", stdout);
    int n, t;
    cin >> n >> t;
    vector<ll> a;
    forr(i, 1, n+1){
        ll x, y; cin >> x >> y;
        a.pb(x + y * t);
    }
    cout << res(a);
}