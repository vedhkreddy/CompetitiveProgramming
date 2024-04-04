#include <bits/stdc++.h>
using namespace std;

/*
    Observation 1: we only care about subsegments
    Observation 2: we could unnecessarily connect two components
        this is by removing
    
    Method 1: Greedy
        iterate and add until creates a discnonect
        then go to the other one
        Problem: doens't account for creation
*/

int main(){
    int n; cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    vector<int> first; vector<int> second;
    int cur = 1;
    first.push_back(v[0]);
    for(int i = 1; i < n; i++){
        if (v[i-1] == v[i]){
            if (cur == 1){
                cur = 2;
                second.push_back(v[i]);
            }
            else{
                cur = 1;
                first.push_back(v[i]);
            }
        }
        else{
            if (cur == 1){
                first.push_back(v[i]);
            }
            else{
                second.push_back(v[i]);
            }
        }
    }
    int res = 0;
    for(int i = 1; i < first.size(); i++){
        if (first[i-1] != first[i]){
            res++;
        }
    }
    for(int i = 1; i < second.size(); i++){
        if (second[i-1] != second[i]){
            res++;
        }
    }
    if (first.size() != 0)res++;
    if (second.size() != 0) res++;
    cout << res << endl;
}