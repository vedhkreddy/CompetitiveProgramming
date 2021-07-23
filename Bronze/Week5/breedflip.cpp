#include <iostream>
#include <fstream>
using namespace std;

int solve(int N, char wanted[], char received[]){
    int indexposition = 0;
    int uses = 0;
    for(int i = 0; i < N; i++){
        indexposition = i;
        if (wanted[i] != received[i]){
            int count = 0;
            while (1 == 1){
                indexposition++;
                if (wanted[indexposition] != received[indexposition]){
                    count++;
                }
                else{
                    break;
                }
            }
            i += count;
            uses++;
        }
    }
    return uses;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1012
    ifstream fin("breedflip.in");
    ofstream fout("breedflip.out");
    int N;
    fin >> N;
    char A[N];
    char B[N];
    for(int i = 0; i < N; i++){
        fin >> A[i];
    }
    for(int i = 0; i < N; i++){
        fin >> B[i];
    }
    int solution = solve(N, A, B);
    fout << solution;
}