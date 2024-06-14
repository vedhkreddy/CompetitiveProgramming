#include <bits/stdc++.h>
#include <set>
using namespace std;

/*

*/

void solve(){
    long long n; cin >> n;
    vector<long long> v;
    for (long long i = 0; i < n; i++){
        long long a; cin >> a; v.push_back(a);
    }
    map<pair<long long, long long>, long long> m1;
    map<pair<long long, long long>, long long> m2;
    map<pair<long long, long long>, long long> m4;
    map<vector<long long>, long long> m3;
    for(long long i = 0; i < n-2; i++){
        pair<long long, long long> p1 = make_pair(v[i], v[i+1]);
        pair<long long, long long> p2 = make_pair(v[i+1], v[i+2]);
        pair<long long, long long> p4 = make_pair(v[i], v[i+2]);
        vector<long long> p3 = {v[i], v[i+1], v[i+2]};
        if (m1.count(p1) == 0) m1[p1] = 1;
        else{m1[p1]++;}
        if (m2.count(p2) == 0) m2[p2] = 1;
        else{m2[p2]++;}
        if (m4.count(p4) == 0) m4[p4] = 1;
        else{m4[p4]++;}
        if (m3.count(p3) == 0) m3[p3] = 1;
        else{m3[p3]++;}
    }
    long long res = 0;
    for(long long i = 0; i < n-2; i++){
        pair<long long, long long> p1 = make_pair(v[i], v[i+1]);
        pair<long long, long long> p2 = make_pair(v[i+1], v[i+2]);
        pair<long long, long long> p4 = make_pair(v[i], v[i+2]);
        vector<long long> p3 = {v[i], v[i+1], v[i+2]};
        res += m1[p1] - 1;
        res += m2[p2] - 1;
        res += m4[p4] - 1;
        res -= ((m3[p3] - 1) * 3);
    }
    res /= 2;
    cout << res << endl;
}

int main(){
    long long t; cin >> t;
    for(long long i = 0; i < t; i++){
        solve();
    }
}