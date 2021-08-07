#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int solve(int N, int stalls[]){
    int big1 = 0;
    int big2 = 0;
    for(int i = 0; i < N; i++){
        int count = 0;
        if (stalls[i] == 0){
            int indexposition = i;
            while (stalls[indexposition] == 0 && indexposition != N){
                count++;
                indexposition++;
            }
            i = indexposition - 1;
        }
        if (count > big1){
            big2 = big1;
            big1 = count;
        }
        else if(count > big2){
            big2 = count;
        }
    }
    if (ceil(float(big1) / 4) > ceil(float(big2) / 2)){
        return ceil(float(big1) / 4);
    }
    return ceil(float(big2) / 2);
}

int main(){
    ifstream fin("socdist1.in");
    ofstream fout("socdist1.out"); 
    int N;
    fin >> N;
    int stalls[N];
    for(int i = 0; i < N; i++){
        char a;
        fin >> a;
        int b = int(a) - 48;
        stalls[i] = b;
    }

    int solution = solve(N, stalls);
    fout << solution;
}