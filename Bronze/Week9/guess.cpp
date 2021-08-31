#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=664
    ifstream fin("guess.in");
    ofstream fout("guess.out");
    int N;
    fin >> N;
    map<string, vector<string>> animals;
    for(int i = 0; i < N; i++){
        string a;
        fin >> a;
        int b;
        fin >> b;
        animals[a] = {};
        for(int j = 0; j < b; j++){
            string c;
            fin >> c;
            animals[a].push_back(c);
        }
    }
    int big = 0;
    for(auto const&x : animals){
        for(auto const &y : animals){
            int counter = 0;
            if (y.first.compare(x.first) != 0){
                for (string s : x.second){
                    for(string z : y.second){
                        if (z.compare(s) == 0){
                            counter++;
                        }
                    }
                }
            }
            if (counter > big){
                big = counter;
            }
        }
    }
    fout << big + 1;
}