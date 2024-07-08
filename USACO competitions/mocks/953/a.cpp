#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin >> t;
    while (t--){
        int n, i, j, k, ans = 0, x, y, z;
        vector<int> v(3,0);
        for (i = 0; i < 3; i++)
            cin >> v[i];
        sort(v.begin(),v.end());
        ans += v[1]-v[0];
        ans += v[2]-v[1];
        cout<< ans << endl;
    }
}