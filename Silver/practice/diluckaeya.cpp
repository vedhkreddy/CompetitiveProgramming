#include <bits/stdc++.h>
using namespace std;

/*
1. we can store d's and k's for each substring
2. we can use o(nlogn)
store D's and K's


Algo
1. iterate forwards
2. find prime factors for i
    3. go backwards for each prime factor k/p
    going backwards takes a long time
*/
const int mxn = 5e5+5;

pair<int, int> rat(int a, int b){
    int x = gcd(a, b);
    a /= x; b /= x;
    return {a, b};
}

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    int d = 0; int k = 0;
    map<pair<int, int>, int> m;
    for(char c : s){
        if (c == 'D') d++;
        else k++;
        cout << (m[rat(d, k)] + 1) << " ";
        m[rat(d, k)]++;
    }
    cout << endl;
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}