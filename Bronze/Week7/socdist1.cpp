#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int solve(int N, int stalls[]){
    int big = 0;
    int bigstart = 0;
    for(int i = 0; i < N; i++){
        int tmp = i;
        int count = 0;
        if (stalls[i] == 0){
            int indexposition = i;
            while (stalls[indexposition] == 0 && indexposition != N){
                count++;
                indexposition++;
            }
            i = indexposition - 1;
        }
        if (count > big){
            big = count;
            bigstart = tmp;
        }
    }
    if (bigstart == 0){
        stalls[0] = 1;
        return big;
    }
    else if(bigstart + big == N){
        stalls[N-1] = 1;
        return big;
    }
    else{
        stalls[int(bigstart + floor(float(big) / 2))] = 1;
        return ceil(float(big) / 2);
    }

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
    solution = solve(N, stalls);
    fout << solution;
}