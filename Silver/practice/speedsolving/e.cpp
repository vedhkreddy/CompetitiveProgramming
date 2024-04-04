#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    long long t; cin >> t;
    while (t--){
        int n; cin >> n;
        string s; cin >> s;
        reverse(s.begin(), s.end());
        int periods[n + 5];
        for(int i = 0; i < n; i++){
            periods[n - i - 1] = 2;;
            if (s[0] == 'V') i += 2;
            else{
                i += 3;
            }
        }
        reverse(s.begin(), s.end());
        for(int i = 0; i < n-1; i++){
            if (periods[i] == 2){
                cout << ".";
            }
            cout << s[i];
        }
        cout << s[n-1] << endl;
    }
}