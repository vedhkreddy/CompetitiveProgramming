#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, c, m;
    cin >> n >> c >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }  
    int all = 0;
    for (vector<int> vv : v){
        if (c > vv[2]){
            c == vv[2] - 1;
        }
        if (m > vv[2]){
            m == vv[2] - 1;
        }
    }
    for (ve)
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve;
    }
}