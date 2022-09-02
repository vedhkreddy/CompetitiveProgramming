#include <iostream>
#include <fstream>
using namespace std;

/*
int sumpref(int a, int b, int c, int d){
    return pref[a][b] - pref[c][b] - pref[a][d] + pref[c][d];
}
*/

int main(){
    int arr[2][2];
    int pref[3][3];
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            pref[i][j] = 0;
        }
    }
    ifstream cin("prefix.in");
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }

    for (int i = 1; i >= 0; i--){
        for (int j = 1; j >= 0; j--){
            pref[i][j] = pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1] + arr[i][j];
        }
    }

    //cout << sumpref(2, 2, 3, 3);
}

