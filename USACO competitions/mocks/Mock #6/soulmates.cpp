#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
#define sz(x) (int)(x.size())


int main(){
    int t; cin >> t;

    for (int l = 0; l < t; l++){
        ll a, b;
        cin >> a >> b;
        if (a == b){cout << 0 << endl; continue;}
        vector<ll> div1 = {a}, div2 = {b};
        while (a > 1){
            if (a % 2 == 1){
                a++;
            }
            else{
                a /= 2;
            }
            div1.push_back(a);
        }
        div1.push_back(1);
        while (b > 1) {
            if (b % 2) {
                b--;
            } else {
                b /= 2;
            }
            div2.push_back(b);
        }
        div2.push_back(1);
        ll ans = 100000000000000;
        for (int i = 0; i < sz(div1); i++) {
            for (int j = 0; j < sz(div2); j++) {
                if (div1[i] < div2[j]) {
                    ans = min(div2[j] - div1[i] + i + j, ans);
                }
            }
	    }
	    cout << ans << '\n';
    }
}