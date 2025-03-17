#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        int n;
        cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++){
            int a; cin >> a;
            if (m.find(a) == m.end()){
                m[a] = 1;
            }
            else{
                m[a]++;
            }
        }
        int res = 0;
        map<int, int>::iterator it;
        for (it = m.begin(); it != m.end(); it++){
            res += (it->second)/2;
        }
        cout << res << endl;
    }
}