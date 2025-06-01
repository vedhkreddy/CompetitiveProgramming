#include <bits/stdc++.h>
using namespace std;

#define str string
#define ump unordered_map

int main(){
    str s, t; 
    cin >> s >> t;
    ump<char, int> s_, t_;
    for (int i = 1; i < s.size(); i++){
        if (!s_.count(s[i])) s_[s[i]] = i;
    }
    for (int j = t.size() - 2; j >= 0; j--){
        if (!t_.count(t[j])) t_[t[j]] = j + 1;
    }
    int bestSum = INT_MAX, bestX = -1, bestY = -1;
    for (int i = 0; i < s.size(); i++){
        if (s_.count(s[i]) && t_.count(s[i])){
            int cur = s_[s[i]] + 1 + t.size() - t_[s[i]];
            if (cur < bestSum){
                bestSum = cur;
                bestX = s_[s[i]];
                bestY = t_[s[i]] - 1;
            }
        }
    }
    if (bestX == -1){
        cout << "-1" << endl;
        return 0;
    }
    cout << s.substr(0, bestX + 1) << t.substr(bestY + 1) << endl;
    return 0;
}
