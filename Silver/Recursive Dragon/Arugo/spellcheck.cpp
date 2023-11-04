#include <bits/stdc++.h>
using namespace std;

int main(){
    string s = "Timur";
    sort(s.begin(), s.end());
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n; cin >> n; string l; cin >> l;
        sort(l.begin(), l.end());
        if (l == s) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}