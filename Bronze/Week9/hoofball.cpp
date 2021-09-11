#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=808
    ifstream fin("hoofball.in");
    ofstream fout("hoofball.out");
    int N;
    fin >> N;
    vector<int> cows;
    for(int i = 0; i < N; i++){
        int a;
        fin >> a;
        cows.push_back(a);
    }
    sort(cows.begin(), cows.end());
    vector<vector<int>> sequences;
    for(int i = 0; i < N; i++){
        vector<int> positions;
        int indexposition = i;   
        positions.push_back(indexposition);
        while (1==1){
            if (indexposition == 0){
                indexposition++;
            }
            else if(indexposition == N-1){
                indexposition--;
            }
            else if(cows[indexposition + 1] - cows[indexposition] < abs(cows[indexposition - 1] - cows[indexposition])){
                indexposition++;
            }
            else{
                indexposition--;
            }
            if (positions.size() < 2){
                positions.push_back(indexposition);
            }
            else if(positions[positions.size() - 2] == indexposition){
                break;
            }
            else{
                positions.push_back(indexposition);
            }
        }
        vector<int> covered;
        for(int j : positions){
            covered.push_back(cows[j]);
        }
        sequences.push_back(covered);
    }

    set<int> cowscovered;
    int count = 0;
    set<int> cows1;
    for(int i : cows){
        cows1.insert(i);
    }
    while (cowscovered != cows1){
        count++;
        vector<int> biggest;
        for(vector<int> v : sequences){
             if (v.size() > biggest.size()){
                biggest = v;
            }
        }
        for(int i : biggest){
            cowscovered.insert(i);
        }
        auto position = find(sequences.begin(), sequences.end(), biggest);
        if (position != sequences.end()){
            sequences.erase(position);
        }
        for(int i = 0; i < sequences.size(); i++){
            for(int j : cowscovered){
                auto position = find(sequences[i].begin(), sequences[i].end(), j);
                if (position != sequences[i].end()){
                    sequences[i].erase(position);
                }
            }
        }
    }
    fout << count;
}
