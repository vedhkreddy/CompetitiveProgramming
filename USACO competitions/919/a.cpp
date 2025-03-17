#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<char> vc;
    for (int i = 0 ; i < n; i++){
        char c; cin >> c; vc.push_back(c);
    }
    vector<char> squished;
    if (vc.size() == 1){
        cout << "YES" << endl;
        return;
    }
    squished.push_back(vc[0]);
    for (int i = 1; i < n; i++) {
        if (vc[i] != vc[i-1]) {
            squished.push_back(vc[i]);
        }
    }
    set<char> s(squished.begin(), squished.end());
    if (s.size() != squished.size()){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}