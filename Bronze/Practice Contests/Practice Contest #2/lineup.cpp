#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    ifstream fin("lineup.in");
    ofstream fout("lineup.out");
    int N;
    fin >> N;
    map<string, vector<string>> demands = {};
    for(int i = 0; i < N; i++){
        string a, b, c, d, e, f;
        fin >> a >> b >> c >> d >> e >> f;
        demands[a].push_back(f);
        demands[f].push_back(a);
    }
    vector<string> cows = {"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    vector<vector<string>> working;
    do {
        bool bad = false;
        for(int i = 0; i < 8; i++){
            if (demands[cows[i]].size() == 0){
                continue;
            }
            else if (demands[cows[i]].size() == 1){
                if (i == 0){
                    if (demands[cows[i]][0].compare(cows[1]) != 0){
                        bad = true;
                    }
                }
                else if (i == 7){
                    if (demands[cows[i]][0].compare(cows[6]) != 0){
                        bad = true;
                    }
                }
                else{
                    if (demands[cows[i]][0].compare(cows[i+1]) != 0 && demands[cows[i]][0].compare(cows[i - 1]) != 0){
                        bad = true;
                    }
                }
            }
            else if(demands[cows[i]].size() == 2){
                if (i == 0 || i == 7){
                    bad = true;
                }
                else if ((demands[cows[i]][0].compare(cows[i+1]) != 0 && demands[cows[i]][0].compare(cows[i - 1]) != 0) || (demands[cows[i]][1].compare(cows[i+1]) != 0 && demands[cows[i]][1].compare(cows[i - 1]) != 0)){
                    bad = true;
                }
            }
        }
        if (bad != true){
            working.push_back(cows);
        }
    } while (next_permutation(cows.begin(), cows.end()));
    sort(working.begin(), working.end());
    for(int i = 0; i < 8; i++){
        fout << working[0][i] << endl;
    }
}