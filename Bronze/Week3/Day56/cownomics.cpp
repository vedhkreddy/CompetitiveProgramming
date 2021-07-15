#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=736
    ifstream fin("cownomics.in");
    ofstream fout("cownomics.out");
    vector<string> spotty;
    vector<string> plain;
    int n, m;
    fin >> n >> m;
    for(int i = 0; i < n; i++){
        string a;
        fin >> a;
        spotty.push_back(a);
    }
    for(int i = 0; i < n; i++){
        string a;
        fin >> a;
        plain.push_back(a);
    }
    int bigcount = 0;
    for(int i = 0; i < m; i++){
        set<char> spottedi;
        set<char> plaini;
        for(string s : spotty){
            spottedi.insert(s[i]);
        }
        for(string s : plain){
            plaini.insert(s[i]);
        }
        if ((spottedi.count('A') && plaini.count('A')) || (spottedi.count('C') && plaini.count('C')) || (spottedi.count('T') && plaini.count('T')) || (spottedi.count('G') && plaini.count('G'))){

        }
        else{
            bigcount++;
        }
    }
    fout << bigcount;    
}