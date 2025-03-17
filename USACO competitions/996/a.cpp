#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; int a; int b; cin >> a >> b;
        if (abs(a-b) % 2 == 0) cout << "YES" << endl;
        else{cout << "NO" << endl;}
    }
}