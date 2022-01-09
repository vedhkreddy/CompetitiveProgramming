#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //ifstream cin("this.in");
    int t;
    cin >> t;
    vector<string> lists;
    for (int i = 0; i < t; i++){
        int a;
        cin >> a;
        string s;
        cin >> s;
        lists.push_back(s);
    }

    for (string v : lists){
        int T = 0;
        int M = 0;
        bool bad = false;
        for (char i : v){
            if (i == 'T'){
                T++;
            }
            else{
                M++;
            }
            if (T < M){
                bad = true;
            }
        }
        if (M * 2 != T){
            bad = true;
        }
        M = 0;
        T = 0;
        for (int i = v.size() - 1; i >= 0; i--){
            if (v[i] == 'M'){
                M++;
            }
            else{
                T++;
            }
            if (T < M){
                bad = true;
            }
        }
        if (bad == true){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
}