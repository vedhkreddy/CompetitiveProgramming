#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        vector<int> a;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            a.push_back(x);
        }
        
        vector<int> f(n);
        int l = n;
        int r = n;
        multiset<int> b;
        
        for (int i = n-1; i >= 0; i--){
            if (l >= r || a[i] <= f[l]){
                f[--l] = a[i];
            }
            else{
                b.insert(a[i] + 1);
            }
            
            while (l < r && !b.empty() && 
                   f[r - 1] > *b.begin()){
                b.insert(f[r - 1] + 1);
                r--;
            }
        }
        
        vector<int> v;
        for (int i = l; i < r; i++){
            v.push_back(f[i]);
        }
        for (auto x : b){
            v.push_back(x);
        }
        
        for (auto x : v){
            cout << x << " ";
        }
        cout << endl;
    }
}