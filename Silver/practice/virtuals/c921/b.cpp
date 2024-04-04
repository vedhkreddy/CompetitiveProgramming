#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x){
    int ans = -INT_MAX;
    for(int i = 1; i <= sqrt(n); i++){
        if (n % i == 0){
            if (n/i >= x && i > ans) ans = i;
            if (i >= x && n/i > ans) ans = n/i;
        }
    }
    return ans;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n, x; cin >> n >> x;
        cout << solve(n, x) << endl;
    }
}