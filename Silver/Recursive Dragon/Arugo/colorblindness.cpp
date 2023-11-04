#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0 ; i < t; i++){
        int n; cin >> n;
        string a; string b; cin >> a >> b;
        bool good = true;
        for(int i = 0; i < n; i++){
            if (a[i] == 'G') a[i] = 'B';
            if (b[i] == 'G') b[i] = 'B';
            if (a[i] != b[i]){cout << "NO" << endl; good = false; break;}
        }
        if (good == true)cout << "YES" << endl;
    }
}