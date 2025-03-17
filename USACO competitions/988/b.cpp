#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            m[a] = 1;
        }
        for (int i = 1; i <= n-2; i++){
            int x = n-2;
            if (x % i == 0){
                int y = x/i;
                if (m.find(i) != m.end() && m.find(y) != m.end()){
                    cout << i << " " << y << endl;
                    break;
                }
            }
        }
    }
}