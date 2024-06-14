#include <bits/stdc++.h>
#include <set>
using namespace std;

/*

*/

void solve(){
    int n; cin >> n;
    vector<char> v;
    set <int> s;
    for (int i = 0; i < n; i++){
        char c; cin >> c;
        v.push_back(c);
        s.insert(c);
    }
    vector<char> r(s.begin(), s.end());
    int p1 = 0; int p2 = r.size() - 1;
    unordered_map<char, char> m;
    while(p1 <= p2){
        m[r[p1]] = r[p2];
        m[r[p2]] = r[p1];
        //cout << r[p1] << " " << r[p2] << endl;
        p1++;
        p2--;
    }
    vector<char> res;
    for(int i = 0; i < n; i++){
        res.push_back(m[v[i]]);
        //cout << m[v[i]] << endl;
    }
    for(int i = 0; i < n; i++){
        cout << res[i];
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}