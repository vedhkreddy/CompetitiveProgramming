#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while (t--){
        vector<char> v;
        for(int i = 0; i < 3; i++){
            v.clear();
            char a, b, c; cin >> a >> b >> c;
            v.push_back(a); v.push_back(b); v.push_back(c);
            bool founda = false; bool foundb = false; bool foundc = false;
            for(int j : v){
                if (j == 'A') founda = true;
                if (j == 'B') foundb = true;
                if (j == 'C') foundc = true;
            }
            if (a == '?' || b == '?' || c == '?'){
                //cout << "here" << endl;
                if (founda == false){
                    cout << "A" << endl;
                }
                if (foundb == false){
                    cout << "B" << endl;
                }
                if (foundc == false){
                    cout << "C" << endl;
                }
            }
        }
    }
}