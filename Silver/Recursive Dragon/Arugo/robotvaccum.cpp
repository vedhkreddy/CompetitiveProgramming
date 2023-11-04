#include <iostream>
using namespace std;
int a[10000000];
int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        bool flag = 0;
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i + 1]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            cout << 0 << endl;
        } else {
            int ans = INT_MAX;
            for(int i = 1; i < n; i++)
                ans = min(ans, abs(a[i + 1] - a[i]));
            cout << ans / 2 + 1 << endl;
        }
    }
}