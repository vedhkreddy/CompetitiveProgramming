#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll pref[200000];
ll list1[200000];
ll original[200000];
ll sorted[200000];

ll findIndexInSortedArray(ll original[], ll sorted[], ll n, ll index) {
    ll key = original[index];
    ll* lower = lower_bound(sorted, sorted+n, key);
    if (lower == sorted+n || *lower != key) {
        return -1;
    } else {
        return lower - sorted;
    }
}



int main(){
    //ifstream cin("test.txt");
    ll n; cin >> n;
    for (ll i = 0; i < n; i++){
        cin >> original[i];
        sorted[i] = original[i];
    }
    sort(sorted, sorted + n);

    ll tot = 0;
    for (ll i = 0; i < n; i++){
        tot += (i + 1) * sorted[i];
        pref[i+1] = sorted[i] + pref[i];
    }
    ll q; cin >> q;
    while(q--){
        ll a, b; cin >> a >> b;
        //binary search to find number and then increase/decrease
        a--;
        ll ans = tot;
        ll y = findIndexInSortedArray(original, sorted, n, a);
        //calculate the position at which it needs to get put (increase rest or decrease rest)
        auto x = lower_bound(sorted, sorted + n, b) - sorted - (bool) (b > sorted[y]);
        ans -= (y+1) * sorted[y];
        if (x >= y){
            ans -= pref[x + 1] - pref[y + 1];
        } 
        else{
            ans += pref[y] - pref[x];
        }
        ans += (x + 1) * b;
        cout << ans << endl;;
    }
}
