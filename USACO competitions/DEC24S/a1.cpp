#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main(){
        //ifstream cin("inp.in");
    int t; cin >> t;

    while (t--){
        int n; cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            v.push_back(a);
        }
        int bessie = 0;
        int rmid = n/2;
        int lmid = rmid - 1;
        bessie += (v[rmid] + v[lmid]);
        while (rmid < n-1 && lmid > 0){
            if (v[rmid + 1] > v[lmid - 1]){
                bessie += v[lmid - 1]; rmid--;
            }
            else{
                bessie += v[rmid + 1]; lmid++;
            }
        }
        cout << bessie << endl;
    }
}