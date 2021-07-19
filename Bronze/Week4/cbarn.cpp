#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=616
    ifstream fin("cbarn.in");
    ofstream fout("cbarn.out");
    int N;
    fin >> N;
    int places[N];
    for(int i = 0; i < N; i++){
        fin >> places[i];
        cout << places[i] << endl;
    }
    double smallcount = 5e10;
    for(int i = 0; i < N; i++){
        int indexposition = i;
        int count = 0;
        int away = 0;
        bool first = true;
        if(i == N-1){
            away++;
            for (int j = 0; j < N-1; j++){
                count += places[j] * away;
                away++;  
            }
            cout << "gothere";
        }
        else{
            for(int j = 0; j < N; j++){
                count += places[indexposition] * away;
                if (indexposition == i-1 || indexposition == N-1){
                    indexposition = 0;
                    away++;
                    continue;
                }
                first = false;
                indexposition++;
                away++;
            }
        }

        if (count < smallcount){
            smallcount = count;
        }
    }
    
    fout << int(smallcount);
}