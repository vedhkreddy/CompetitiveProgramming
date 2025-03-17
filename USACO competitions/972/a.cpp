#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int times[6];
    for (int i = 0; i < 5; i++) times[i] = 0;
    for (int i = 0; i < n; i++){
        times[i%5]++;
    }
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < times[i]; j++){
            cout << vowels[i%5];
        }
    }
    cout << endl; 
}

int main(){
    int t; cin >> t;
    while (t--){
        solve();
    }
}