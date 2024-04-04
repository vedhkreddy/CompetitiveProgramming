#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb push_back
#define forr(i,a,b) for (int i = (a); i < (b); i++)

int n, k;
vi a; vi b;
set<int> s;

int solve(){
    vector<int> adj[n+5];
    forr(i, 0, k-1){
        adj[a[i]].pb(a[i+1]);
        //adj[a[i+1]].pb(a[i]);
    }
    
    set<int> ress;
    //adj[a[0]].pb(a[k-1]);
    int res = 0;

    /*
    forr(i, 0, k-1){
        for(int j : adj[b[i]]){
            if (j == b[i+1]){
                ress.insert(b[i]);
                ress.insert(b[i+1]);
                //cout << b[i] << " " << b[i+1] << endl;
            }
        }
    }
    */
    /*
    for(int j : adj[b[k-1]]){
        if (j == b[0]){
            ress.insert(b[k-1]);
            ress.insert(b[0]);
        }
    }
    
    //find out the other stuff
    res += (n - s.size());
    res += ress.size();
    return res;
    */
   return 0;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    freopen("cycle.in", "r", stdin);
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
    int res1 = solve();
    //reverse(a.begin(), a.end());
    //int res2 = solve();
    cout << max(res1, 0);
}