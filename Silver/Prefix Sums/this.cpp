#include <iostream>
#include <fstream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int sol = 0;
    int list[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> list[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i > 0){
                if (list[i][j] == list[i-1][j]){
                    sol++;
                }
            }
            if (j > 0){
                if (list[i][j] == list[i][j-1]){
                    sol++;
                }
            }
        }
    }
    cout << sol;
}