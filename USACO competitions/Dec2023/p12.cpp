#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef vector<int> vi;
#define pb push_back
#define forr(i,a,b) for (int i = (a); i < (b); i++)
int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("cycle.in", "r", stdin);
    int n, k; cin >> n >> k;
    vi a; vi b;
    set<int> s;
    forr(i, 0, k){
        int x; cin >> x;
        a.pb(x);
        s.insert(x);
    }
    forr(i, 0, k){
        int x; cin >> x;
        b.pb(x);
        s.insert(x);
    }
    
    vector<int> adj[n+1];
    
    forr(i, 0, k-1){
        adj[a[i]].pb(a[i+1]);
        //adj[a[i+1]].pb(a[i]);
    }
    
    set<int> ress;
    //adj[a[0]].pb(a[k-1]);
    
    adj[a[k-1]].pb(a[0]);
    int res = 0;
    
    forr(i, 0, k-1){
        for(int j : adj[b[i]]){
            if (j == b[i+1]){
                ress.insert(b[i]);
                ress.insert(b[i+1]);
                //cout << b[i] << " " << b[i+1] << endl;
            }
        }
    }
    
    for(int j : adj[b[k-1]]){
        if (j == b[0]){
            ress.insert(b[k-1]);
            ress.insert(b[0]);
        }
    }

     /**/
    //find out the other stuff
    res += (n - s.size());
    res += ress.size();
    int a1 = res;
    ress.clear();
    res = 0;
    for(vi v: adj){
        v.clear();
    }
    reverse(a.begin(), a.end());
    forr(i, 0, k-1){
        adj[a[i]].pb(a[i+1]);
        //adj[a[i+1]].pb(a[i]);
    }
    
    //adj[a[0]].pb(a[k-1]);
    adj[a[k-1]].pb(a[0]);
    res = 0;
    forr(i, 0, k-1){
        for(int j : adj[b[i]]){
            if (j == b[i+1]){
                ress.insert(b[i]);
                ress.insert(b[i+1]);
                //cout << b[i] << " " << b[i+1] << endl;
            }
        }
    }
    
    for(int j : adj[b[k-1]]){
        if (j == b[0]){
            ress.insert(b[k-1]);
            ress.insert(b[0]);
        }
    }
    
    //find out the other stuff
    res += (n - s.size());
    res += ress.size();
    cout << max(res, a1) << endl;
    //cout << res << " " << a1;
    
}