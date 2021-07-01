#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<int> unshuffle(int num, vector<int> pattern, vector<int> curlist){
    vector<int> returnlist = {};
    for (int i = 0; i < num; i++){
        returnlist.push_back(0);
    }
    for(int i = num-1; i >= 0; i--){
        returnlist[i] = curlist[pattern[i]-1];
    }
    return returnlist;

}

int main(){
    ifstream fin("shuffle.in");
    ofstream fout("shuffle.out");
    int n;
    fin >> n;
    vector<int> shuffle;
    vector<int> current;
    for(int i = 0; i < n; i++){
        int a;
        fin >> a;
        shuffle.push_back(a);
    }
    for(int i = 0; i < n; i++){
        int a;
        fin >> a;
        current.push_back(a);
    }
    vector<int> firstshuffle = unshuffle(n, shuffle, current);
    vector<int> secondshuffle = unshuffle(n, shuffle, firstshuffle);
    vector<int> thirdshuffle = unshuffle(n, shuffle, secondshuffle);
    for (int i : thirdshuffle){
        fout << i << endl;
    }
}