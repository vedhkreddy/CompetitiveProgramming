#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;
    
int types[100];
int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=916
    ifstream fin("revegetate.in");
    ofstream fout("revegetate.out");
    map<int, vector<int>> pastures;
    int N, M;
    fin >> N >> M;
    for (int i = 0; i < N; i++){
        pastures[i + 1] = {};
    }
    for (int i = 0; i < M; i++){
        int a, b;
        fin >> a >> b;
        pastures[a].push_back(b);
        pastures[b].push_back(a);
    }
    for (int i = 1; i <= 4; i++){
        int empty = -1;
        vector<int> dont;
        for (int j = 0; j < N; j++){
            if (types[j] == 0){
                if (empty == -1){
                    empty = j+1;
                    types[j] = i;
                    dont = pastures[empty];
                }
                else{
                    bool found = false;
                    for (int k : dont){
                        if (k == j + 1){
                            found = true;
                        }
                    }
                    if (found == false){
                        types[j] = i;
                        for (int k : pastures[j+1]){
                            dont.push_back(k);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < N; i++){
        fout << types[i];
    }
}