#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;
        vector<long long> a(n, 0);
        int start = x - 1;
        for(int i = 0; i < n; i++){
            int idx = (start + i) % n;
            a[idx] = i % 2;
        }
        if(n % 2 == 1 || ((x - y) % 2 == 0)){
            a[start] = 2;
        }
        for(int i = 0; i < n; i++){
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
}
