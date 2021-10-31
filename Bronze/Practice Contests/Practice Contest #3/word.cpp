#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=987
    ifstream fin("word.in");
    ofstream fout("word.out");
    int N, K;
    fin >> N >> K;
    string words[N];
    for(int i = 0; i < N; i++){
        fin >> words[i];
    }
    int count = 0;
    fout << words[0];
    count = words[0].size();
    for(int i = 1; i < N; i++){
        int charactersize = words[i].size();
        if (K - count - charactersize >= 0){
            fout << " " << words[i];
            count += charactersize;
        }
        else{
            count = charactersize;
            fout << endl << words[i];
        }
    }
}