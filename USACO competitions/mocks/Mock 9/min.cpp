#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n; cin >> n;
        vector<int> v;
        vector<int> p;
        for (int i = 0; i < n; i++){
            int a; cin >> a; v.push_back(a); p.push_back(a);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (int i : p){
            if (i == v[0]){
                cout << (i - v[1]) << " ";
            }
            else{
                cout << (i - v[0]) << " ";
            }
        }
        cout << endl;
    }

}