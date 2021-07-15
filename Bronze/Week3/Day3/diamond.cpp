#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=639
    ifstream fin("diamond.in");
    ofstream fout("diamond.out");
    int N, K;
    fin >> N >> K;
    int diamonds[N];
    for(int i = 0; i < N; i++){
        int a;
        fin >> a;
        diamonds[i] = a;
    }
    sort(diamonds, diamonds + N);
   
    int bigcount = 0;
    int indexposition = 1;
    for(int i = 0; i < N; i++){
        int count = 1;
        indexposition = i+1;
        while (1 == 1){
            if (indexposition == N){
                if (count > bigcount){
                    fout << count;
                }
                else{
                    fout << bigcount;
                }
                return 0;
            }
            if ((diamonds[indexposition] - diamonds[i]) <= K){
                count++;
                indexposition++;
            }
            else{
                if (count > bigcount){
                    bigcount = count;
                }
                break;
            }
        }
    }
    fout << bigcount;
}