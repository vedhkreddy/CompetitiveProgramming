#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        int cur = 0;
        int res = 0;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            cur += x;
            int sqrtVal = sqrt(cur);
            if (sqrtVal * sqrtVal == cur && sqrtVal % 2 == 1 && cur % sqrtVal == 0){
                res++;
            }
        }
        cout << res << endl;
    }
}