#include<iostream>
#include<string>
using namespace std;

int main(){
    //https://codeforces.com/problemset/problem/133/A
    string a;
    cin >> a;
    bool output = false;
    for(int i = 0; i < a.size(); ++i){
        if (a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
            output = true;
        }
    }
    if(output == false){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
}