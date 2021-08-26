#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int blast(int bales[], int bale, int N){
    vector<int> blastees;
    blastees.push_back(bale);
    int radius = 1;
    set<int> exploded;
    exploded.insert(bale);
    while (blastees.size() != 0){
        vector<int> seplist;
        for(int i = 0; i < N; i++){
            for(int j : blastees){
                if (abs(bales[i] - j) <= radius){
                    bool found = false;
                    for (int k : exploded){
                        if (k == bales[i]){
                            found = true;
                        }
                    }
                    if (found == false){    
                        exploded.insert(bales[i]);
                        seplist.push_back(bales[i]);
                    }
                }
            }
        }
        blastees = seplist;
        radius++;
    }
    return exploded.size();
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=592
    ifstream fin("angry.in");
    ofstream fout("angry.out");
    int N;
    fin >> N;
    int bales[N];
    for(int i = 0; i < N; i++){
        fin >> bales[i];
    }
    sort(bales, bales + N);
    int big = 0;
    for(int i = 0; i < N; i++){
        int count = blast(bales, bales[i], N);
        if (count > big){
            big = count;
        }
    }

    fout << big;
}