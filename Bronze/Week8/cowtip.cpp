#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("cowtip.in");
    ofstream fout("cowtip.out");
    int N;
    fin >> N;
    int cows[N][N];
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            char a;
            fin >> a;
            cows[i][j] = int(a) - 48;
        }
    }
    int counter = 0;
    for(int i = N-1; i > -1; i--){
        for(int j = N-1; j > -1; j--){
            if (cows[i][j] == 1){
                counter++;
                bool ready = true;
                for(int k = 0; k <= i; k++){
                    for(int l = 0; l <= j; l++){
                        if (cows[k][l] == 0){
                            cows[k][l] = 1;
                        }
                        else{
                            cows[k][l] = 0;
                        }
                    }
                }
            }
        }
    }
    fout << counter;
}