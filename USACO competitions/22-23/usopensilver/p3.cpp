#include <bits/stdc++.h>
using namespace std;

int pref[1000000];
int main(){
    ifstream cin("test.in");
    vector<int> v;
    vector<int> original;
    int n; cin >> n;
    int places[10000005];
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
        original.push_back(a);
        places[a] = i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++){
        pref[i+1] = pref[i] + v[i];
    }
    int lgsum = 0;
    map<int, int> sums;
    for (int i = 0; i < n; i++){
        lgsum += v[i] * (i+1);
        sums[v[i]] = v[i] * (i+1);
    }
    cout << "here";
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        int a, b;
        cin >> a >> b;
        a--;
        if (original[a] < b){
            auto z = lower_bound(v.begin(), v.end(), b);
            auto x = z--;
            int y = x - v.begin();
            int offset = pref[y]; - pref[places[original[a]]];
            int cursum = lgsum - offset;
            cursum += (z - v.begin()) * b;
            cursum -= sums[original[a]];
            cout << cursum;
        }
        else if (v[a] > b){

        }
        else{
            cout << lgsum << endl;
        }
    }

}