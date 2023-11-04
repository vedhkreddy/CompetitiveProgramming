#include <iostream>
using namespace std;

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        string s;
        cin >> s;
        char x = s[0];
        int a = x - '0';
        char b  = s[2];
        int c = b - '0';
        cout << a + c << endl;
    }
}