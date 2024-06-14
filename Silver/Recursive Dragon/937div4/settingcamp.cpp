#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int tents = 0;
        tents += a;
        if (b % 3 == 0){
            tents += (b/3);
        }
        if (3 - (b%3) > c){
            cout << "-1" << endl;
            continue;
        }
        else{
            b += (3 - (b%3));
            c -= (3 - (b%3));
            tents += b/3;
            tents += floor(float(c)/3);
        }
    }
}