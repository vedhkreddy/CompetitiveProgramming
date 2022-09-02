#include <iostream>
using namespace std;
#define ll long long

ll pref[50001];
int main(){
    cin.tie(0), cout.sync_with_stdio(0);
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++){
        ll a;
        cin >> a;
        pref[i] = pref[i-1] + a;
    }
    for (int i = 0; i < q; i++){
        ll a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a] << endl;
    }
}