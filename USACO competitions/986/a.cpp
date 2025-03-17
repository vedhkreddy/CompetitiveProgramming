#include <bits/stdc++.h>
using namespace std;

vector<int> process(int x, int y, int a, int b, string s){
    vector<int> res = {x, y, 1};
    for (char c : s){
        if (c == 'N'){
            y++;
        }
        else if (c == 'E'){
            x++;
        }
        else if(c == 'S'){
            y--;
        }
        else{
            x--;
        }
        if (x == a && y == b){
            res[2] = 0;
        }
    }
    res[0] = x;
    res[1] = y;
    return res;
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; int a; int b; cin >> n >> a >> b;
        string s; cin >> s;
        int x = 0; int y = 0;
        int found = false;
        for (int i = 0; i < 20; i++){
            vector<int> p = process(x, y, a, b, s);
            x = p[0];
            y = p[1];
            if (p[2] == 0){
                cout << "YES" << endl;
                found = true;
                break;
            }
        }
        if (found == false){
            cout << "NO" << endl;
        }
    }
}