#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> a(n); vector<int> b(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            cin >> b[i];
        }
        int bad = false;
        pair<int, int> op;
        for (int i = 0; i < n; i++){
            if (b[i] > a[i]){
                bad = true;
                op.first = i;
                op.second = b[i] - a[i];
            }
        }
        if (bad == false) cout << "YES" << endl;
        else{
            for (int i = 0; i < n; i++){
                if (i == op.first) a[i] += op.second;
                else{
                    a[i] -= op.second;
                }
            }
            int good = true;
            for (int i = 0; i < n; i++){
                if (a[i] < b[i]) good = false;
            }
            if (good == false){
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
        }
    }
}