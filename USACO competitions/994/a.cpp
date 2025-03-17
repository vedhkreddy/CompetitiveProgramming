#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        reverse(v.begin(), v.end());
        while (!v.empty() && v.back() == 0)
            v.pop_back();
        reverse(v.begin(), v.end());
        if (v.empty()){
            cout << 0 << endl;
            continue;
        }
        bool x = false;
        for (int i = 0; i < v.size(); i++){
            if (v[i] == 0) x = true;
        }
        if (x) cout << "2" << endl;
        else cout << "1" << endl;
    }
}
