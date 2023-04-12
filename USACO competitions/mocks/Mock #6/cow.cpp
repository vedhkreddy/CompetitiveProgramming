#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int pref[200010][3];
int main(){
    string s; int q;
    cin >> s >> q;
    for (int i = 0; i < (int) s.size(); i++){
        pref[i+1][0] = pref[i][0];
        pref[i+1][1] = pref[i][1];
        pref[i+1][2] = pref[i][2];
        if (s[i] == 'C'){pref[i+1][0]++;}
        if (s[i] == 'O'){pref[i+1][1]++;}
        if (s[i] == 'W'){pref[i+1][2]++;}
    }

    for (int i = 0; i < q; i++){
        int l, r; cin >> l >> r;
        int p1 = (pref[r][0] - pref[l-1][0]) % 2;
        int p2 = (pref[r][1] - pref[l-1][1]) % 2;
        int p3 = (pref[r][2] - pref[l-1][2]) % 2;

        if ((p1 == 1 && p2 == p3 && p2 == 0) || (p1 == 0 && p2 == 1 && p3 == 1)){
            cout << "Y";
            continue;
        }
        cout << "N";
    }
}