#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<char> v(n);
        for (int i = 0; i < n; i++){
            cin >> v[i];
        }
        vector<int> curperm(n, 0);
        for (int i = 0; i < n; i++){
            if (v[i] != 'p') continue;
            int maxcur = i + 1;
            for (int j = 0; j <= i; j++){
                if (curperm[j] == 0){
                    curperm[j] = maxcur;
                    maxcur--;
                }
            }
        }
        int maxcur = n;
        for (int j = 0; j < n; j++){
            if (curperm[j] == 0){
                curperm[j] = maxcur;
                maxcur--;
            }
        }
        reverse(curperm.begin(), curperm.end());
        bool bad = false;
        for (int i = 0; i < n; i++){
            if (v[i] == 'p'){
                int start = n - 1 - i;
                int length = i + 1;
                set<int> vals;
                for (int pos = start; pos < start + length; pos++){
                    vals.insert(curperm[pos]);
                }
                if ((int)vals.size() != length || *vals.begin() != 1 || *vals.rbegin() != length){
                    bad = true;
                    break;
                }
            } else if (v[i] == 's'){
                int length = n - i;
                set<int> vals;
                for (int pos = 0; pos < length; pos++){
                    vals.insert(curperm[pos]);
                }
                if ((int)vals.size() != length || *vals.begin() != 1 || *vals.rbegin() != length){
                    bad = true;
                    break;
                }
            }
        }
        if (bad) cout << "NO" << endl; 
        else cout << "YES" << endl;
    }
}
