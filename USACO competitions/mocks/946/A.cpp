#include <bits/stdc++.h>
using namespace std;

/*

*/
void solve(){
    int x; int y;
    cin >> x >> y;
    int minsq = ceil(float(y) / 2.0);
    //cout << minsq << endl;
    if (y % 2 == 0){
        if (minsq * 7 < x){
            x -= minsq * 7;
            minsq += ceil(float(x)/15.0);
        }
       
    }
    else{
        if ((minsq * 7 + 4) < x){
            x -= minsq * 7;
            x -= 4;
            minsq += ceil(float(x)/15.0);
        }
    }
    cout << minsq << endl;
}

int main(){
    int t; cin >> t;
    for(int i = 0 ; i < t; i++){
        solve();
    }
}