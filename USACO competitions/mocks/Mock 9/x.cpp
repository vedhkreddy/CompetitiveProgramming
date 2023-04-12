#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    ll n; cin >> n;
    set<int> v;
    for (ll i = 0; i < n; i++){
        ll a; cin >> a; v.insert(a);
    }
    cout << v.size() << endl;
}   