#include <bits/stdc++.h>
using namespace std;

vector<char> reverseString(vector<char> s) {
    for (int i = 0; i < s.size()/2; i++){
        int tmp = s[0];
        s[0] = s[s.size() - i - 1];
        s[s.size()-i-1] = tmp;
    }
    return s;
}

int main(){
    vector<char> v = {'a','b','c','d'};
    vector<char> res = reverseString(v);
    for (char c : res){
        cout << c;
    }
    cout << endl;
}