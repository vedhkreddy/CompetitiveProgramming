#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n; n *= 2;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                int x = i/2; int y = j/2;
                if ((x + y) %2 == 0){
                    cout << "#";
                }
                else{
                    cout << ".";
                }
            }
            cout << endl;
        }
    }
}