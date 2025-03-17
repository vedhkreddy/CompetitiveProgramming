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
        int lmid = n/2 - 1;
        int rmid = n/2;
        int r = n-1;
        int l = 0;
        int elsie = 0;
        int bessie = 0;
        if (r - l == 3){
            int left = 0;
            if (v[r] > v[l]){
                elsie += v[r];
                left += v[l];
            }
            else{
                elsie += v[l];
                left += v[r];
            }
            bessie += (v[rmid] + v[lmid] + left);
            cout << bessie << " " << elsie << endl;
            continue;
        }
        bessie += v[rmid];
        bessie += v[lmid];
        int newmid = 0;

        while(rmid <= r && lmid >= l){
            
        if (r - l == 3){
            int left = 0;
            if (v[r] > v[l]){
                elsie += v[r];
                left += v[l];
            }
            else{
                elsie += v[l];
                left += v[r];
            }
            bessie += (v[rmid] + v[lmid] + left);
            cout << bessie << " " << elsie << endl;
        }

            
            //cout << l << " " << lmid << " " << rmid << " " << r << endl;
            bessie += newmid;
            //cout << bessie << endl;
            if (v[r] + v[rmid + 1] > v[l] + v[lmid - 1]){
                elsie += v[r];
                lmid--;
                newmid = v[lmid];
                r--;
            }
            else{
                elsie += v[l];
                rmid++;
                newmid = v[rmid];
                l++;
            }
        }
       // cout << bessie << " " << elsie << endl;
    }
}