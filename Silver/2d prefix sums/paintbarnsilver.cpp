#include <iostream>
#include <fstream>
using namespace std;

int pref[1002][1002];
int arr[1001][1001];
int main(){
    ifstream fin("paintbarn.in");
    ofstream fout("paintbarn.out");
    int n, k;
    fin >> n >> k;
    for (int i = 0; i < n; i++){
        int a, b, c, d;
        fin >> a >> b >> c >> d;
        arr[a][b]++;
        arr[c][d]++;
        arr[a][d]--;
        arr[c][b]--;
    }
    for (int i = 1000; i >= 0; i--){
        for (int j = 1000; j >= 0; j--){
            pref[i][j] = pref[i+1][j] + pref[i][j+1] - pref[i+1][j+1] + arr[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < 1000; i++){
        for (int j = 0; j < 1000; j++){
            if (pref[i][j] == k){
                count++;
            }
        }
    }
    fout << count;
}