#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=665
    ifstream fin("cowsignal.in");
    ofstream fout("cowsignal.out");
    int a, b, c;
    fin >> a >> b >> c;
    vector<vector<char>> originalgrid;
    for(int i = 0; i < a; i++){
        vector<char> line;
        for (int j = 0; j < b; j++){
            char d;
            fin >> d;
            line.push_back(d);
        }
        originalgrid.push_back(line);
    }

    for(vector<char> clist : originalgrid){
        for(int j = 0; j < c; j++){
            for(char character : clist){
                for(int i = 0; i < c; i++){
                    fout << character;
                }
            }
            fout << endl;
        }
    }
}