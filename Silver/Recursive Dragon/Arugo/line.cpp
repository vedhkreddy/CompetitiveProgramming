#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("line.in");
    int t; cin >> t;
    for (int i = 0; i < t; i ++){
        int n; cin >> n;
        deque<int> v;
        for (int j = 0; j < n; j++){
            char c; cin >> c;
            if (c == 'L'){
                v.push_back(0);
            }
            else v.push_back(1);
        }
        int original = 0;
        for(int i = 0; i < n; i++){
            if (v[i] == 0){
                original += i;
            }
            else{
                original += max(n-1-i-1, 0);
            }
        }
        int cur = 0;
        while(cur < n){
            if (v.size() == 0) {cout << original << " "; cur++; continue;}
            if (v[0] == 1){
                v.pop_front();
                continue;
            }
            else{
                original += (v.size() - 1);
                cout << original << " ";
                cur++;
                v.pop_front();
                continue;
            }
            if (v[v.size()-1] == 0) v.pop_back();
            else{
                original += v.size() - 1;
                cur++;
                cout << original << " ";
                v.pop_back();
            }
        }
    }
}