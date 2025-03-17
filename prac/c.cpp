/*
idk try simulating in reverse with taking the smaller one so as to not go llo the negatives
works for samples
*/

#define ll long long

#include <bits/stdc++.h>
using namespace std;

int main(){
    //ifstream cin ("c.in");
    ll t; cin >> t;
    while(t--){
        //each op counts as one
        //working backwards might not be the most optimal way
        bool correct = false;
        ll a, b, c, d; cin >> a >> b >> c >> d;
        ll res = 0;
        while (c >= a && d >= b){
            if (c == a && d == b){
                cout << res << endl;
                correct = true;
                break;
            }
            if (d > c) d -=c;
            else if (c > d) c -= d;
            res++;
        }
        if (correct != true) cout << -1 << endl;
    }
}