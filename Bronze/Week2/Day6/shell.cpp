#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=891
    ifstream fin("shell.in");
    ofstream fout("shell.out");
    vector<int> guesses;
    vector<int> rights = {0,0,0};
    vector<int> shells = {1, 2, 3};
    vector<pair<int, int>> swaps;
    int N;
    fin >> N;
    for(int i = 0; i < N; i++){
        int a,b,c;
        fin >> a >> b >> c;
        swaps.push_back(make_pair(a,b));
        guesses.push_back(c);
    }

    int i = 0;
    for(pair<int, int> p : swaps){
        iter_swap(shells.begin() + p.first - 1, shells.begin() + p.second - 1);
        rights[shells[guesses[i] - 1] - 1]++;
        i++;
    }
    fout << *max_element(rights.begin(), rights.end()) << endl;
}