#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int a; cin >> a; v.push_back(a);
    }
    int prev = k;
    vector<int> ans;
    int additional = 0;
    for (int i : v){
        additional += max((k - i - prev), 0);
        int b = max((k - i - prev), 0);
        ans.push_back(i + b);
        prev = i + b;
    }
    cout << additional << endl;
    for (int i : ans){
        cout << i << " ";
    }
    cout << endl;
}