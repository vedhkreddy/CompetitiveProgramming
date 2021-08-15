#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

void remove(vector<int> &cows, int bessieposition, int bessieheight){
    auto itr = cows.begin();
    unordered_set<int> s;
 
    for (auto curr = cows.begin(); curr != cows.end(); curr++){
        if (s.insert(*curr).second) {
            *itr++ = *curr;
        }
    }
 
    cows.erase(itr, cows.end());
    for(int i = 0; i < cows.size(); i++){
        if (cows[i] == bessieheight && i != bessieposition){
            cows.erase(cows.begin() + i-1);
            cows.insert(cows.begin()+i-1, bessieheight);
        }

    }
}

int solve(int N, vector<int> cows){
    int length = cows.size();
    N = length;
    int bessieheight = 0;
    int bessieposition = 0;
    for(int i = 0; i < N; i++){
        if (i == 0 && cows[i + 1] <= cows[i]){
            bessieheight = cows[i];
            bessieposition = i;
        }
        else{
            if(i == N - 1){
                if (cows[i - 1] > cows[i]){
                    bessieposition = i;
                    bessieheight = cows[i];
                }
            }
            else if(cows[i - 1] > cows[i] && cows[i - 2] <= cows[i - 1]){
                bessieheight = cows[i];
                bessieposition = i;
            }
            else if (cows[i - 1] > cows[i] && cows[i - 2] <= cows[i - 1]){
                bessieposition = i-1;
                bessieheight = cows[i-1];
            }
        }
    }
    vector<int> cows1;
    for(int i : cows){
        cows1.push_back(i);
    }
    int iposition = 0;
    for(int i = 0; i < cows.size(); i++){
        if (cows[i] == bessieheight){
            iposition = i;
        }
    }
    sort(cows.begin(), cows.end());
    int solution = 0;
    for (int i = 0; i < N - 1; i++){
        if (cows[i] == bessieheight){
            solution = abs(bessieposition - i);
        }
    }
    remove(cows, bessieposition, bessieheight);
    return solution;
    vector<int> seen;
    for(int i = 0; i < cows.size(); i++){
        bool already = false;
        for(int j : seen){
            if (j == cows[i]){
                cout << "gothere";
                solution--;
                already = true;
            }
        }
        if (already == false){
            seen.push_back(cows[i]);
        }
    }
    return solution;
}

int main(){
    ifstream fin("outofplace.in");
    ofstream fout("outofplace.out");
    int N;
    fin >> N;
    vector<int> cows;
    for(int i = 0; i < N; i++){
        int a;  
        fin >> a;
        cows.push_back(a);
    }
    int solution = solve(N, cows);
    fout << solution;
}