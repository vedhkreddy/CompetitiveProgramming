#include <bits/stdc++.h>
using namespace std;
 
void build (vector<int> a, vector<int> &res, int lvl, int of) {
    if (a.empty()) return;
    int mi = 0;
    for (int i = 0; i < a.size(); i++)
        if (a[i] > a[mi]) mi = i;
 
    vector<int> l, r;
    for (int i = 0; i < a.size(); i++)
        if (i < mi) l.push_back(a[i]);
        else if( i > mi) r.push_back(a[i]);
 
    res[of + mi] = lvl;
    build(l, res, lvl + 1, of), build(r, res, lvl + 1, of + mi + 1);
}
 
int main () {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> res(n, 0);
        for (auto &x : a) cin >> x;
 
        build(a, res, 0, 0);
 
        for (auto &x : res) cout << x << " ";
        cout << endl;
    }
}