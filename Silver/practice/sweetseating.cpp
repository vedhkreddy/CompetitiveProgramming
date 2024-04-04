#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200005;
int psum[mxn];
int x[mxn];
int sum;

int32_t main(){
    int n; int m; cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> x[i];
    }
    sort(x, x+n);
    for(int i = 1;i <= n; i++){
        sum += x[i-1]; psum[i] = sum; 
        if (i > m){
            psum[i] += psum[i-m];
        }
    }
    for(int i = 1; i <= n; i++){
        cout << psum[i] << " ";
    }
    cout << endl;
}