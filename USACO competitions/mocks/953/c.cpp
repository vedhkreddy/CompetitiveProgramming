#include <bits/stdc++.h>
#define int long long
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
using namespace std;
signed main() {
    int t; cin >>t;
    while(t--){
        int n,m; cin >> n >> m;
        string s;
        cin >> s;
        vector<int> a(m);
        vector<bool> b(n);
        for (int i = 0; i < m; i++) {
            cin >> a[i];
            b[a[i]-1] = true;
        }
        vector<int> r;
        for (int i = 0; i < n; i++) {
            if(b[i]) r.push_back(i);
        }
        string x; cin >> x;
        sort(all(x));
        for (int i = 0; i < sz(r); i++)
        {
            s[r[i]] = x[i];
        }
        cout << s << endl;
    }
}