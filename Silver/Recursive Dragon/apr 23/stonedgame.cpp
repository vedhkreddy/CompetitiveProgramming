#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n;
        vector<int> v;
        cin >> n;
        int max = -1;
        int sum = 0;
        for (int i = 0 ; i < n; i++){
            int a; cin >> a; v.push_back(a);
            if (a > max){
                max = a;
            }
            sum += a;
        }
        if ((sum - max) < max){
            cout << "T" << endl;
        }
        else if (sum % 2 == 0){
            cout << "HL" << endl;
        }
        else{
            cout << "T" << endl;
        }
    }
}