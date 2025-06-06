#include <bits/stdc++.h>
using namespace std;

/*
if it is completly notoptimal initially, then take the last max value and put it in the beginning, and then run the algo of finding the next max
*/

bool lex(int a, int b){
    string s1 = to_string(a);
    string s2 = to_string(b);
    return s1 < s2;
}

vector<int> genmax(vector<int> a, int n){
    vector<int> max(n);
    //calculate suffix maxes according to lexicographical order
    reverse(a.begin(), a.end());
    max[0] = a[0];
    for (int i = 1; i < n; i++){
        if (max[i-1] > a[i]) max[i] = max[i-1];
        else{
            max[i] = a[i];
        }
    }
    reverse(max.begin(), max.end());
    return max;
}

vector<int> operate(vector<int> a){
    vector<int> max = genmax(a, a.size());
    vector<int> res;
    int mx = max[0];
    for (int i = a.size()-1; i >= 0; i--){
        if (a[i] == mx){
            //cout << i << endl;
            a.erase(a.begin() + i);
            res.push_back(mx);
            break;
        }
    }
    //for (int i = 0; i < a.size(); i++) cout << a[i] << " ";
    //cout << endl;
    max = genmax(a, a.size());
    int cur = 0;
    while (cur >= 0 && cur < a.size()){
        int mx1 = max[cur];
        for (int i = cur; i < a.size(); i++){
            if (a[i] == mx1){
                res.push_back(mx1);
                cur++;
                break;
            }
            cur = i + 1;
        }
    }
    return res;
}

int main(){
    //ifstream cin("a.in");
    int t; cin >> t;
    for(int tc = 0; tc < t; tc++){
        if (tc > 0) cout << endl;
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> max = genmax(a, n);
        //for (int i = 0; i < n; i++) cout << max[i] << " " << endl;
        //figure out up to which place its already placed best
        int pos = -1;
        for (int i = 0; i < n; i++){
            if (a[i] != max[i]){
                pos = i;
                break;
            }
        }
        if (pos == -1){
            for (int i = 0; i < n; i++) {cout << a[i]; if (i != (n-1)) { cout << " ";}};
        }
        else{
            vector<int> b;
            for (int i = pos; i < n; i++) b.push_back(a[i]);
            vector<int> res = operate(b);
            for (int i = 0; i < pos; i++) cout << a[i] << " ";
            for (int i = 0; i < res.size(); i++){ cout << res[i]; if (i != res.size() - 1) {cout << " ";}};
        }
    }
}