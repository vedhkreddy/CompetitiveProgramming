#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while(t--){
            int n;
            cin >> n;
            vector<int> a(n), c(n, 0);
            long long res = 0;
            for(int i = 0; i < n; i++){
                    cin >> a[i];
                    res += a[i];
            }
            for(int i = 0; i < n - 1; i++){
                    int x, y;
                    cin >> x >> y;
                    x -= 1;
                    y -= 1;
                    c[x] += 1;
                    c[y] += 1;
            }
            vector<int> v;
            for(int i = 0; i < n; i++){
                    c[i] -= 1;
                    for(int j = 0; j < c[i]; j++){
                            v.push_back(a[i]);
                    }
            }
            sort(v.begin(), v.end());
            reverse(v.begin(), v.end());
            cout << res << " ";
            for(int x: v){
                    res += x;
                    cout << res << ' ';
            }
            cout << endl;
    }
}