#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=688
    ifstream fin("hps.in");
    ofstream fout("hps.out");
    int n;
    int bigcount = 0;
    fin >> n;
    vector<pair<int, int>> games;
    for(int i = 0; i < n; i++){
        int a, b;
        fin >> a >> b;
        pair<int, int> c = make_pair(a, b);
        games.push_back(c);
    }
    vector<vector<string>> possibilities = {{"hoof", "paper", "scissors"}, {"hoof", "scissors", "paper"}, {"paper", "scissors", "hoof"}, {"paper", "hoof", "scissors"}, {"scissors", "hoof", "paper"}, {"scissors", "paper", "hoof"}};
    for(int i = 0; i < 6; i++){
        int count = 0;
        for(pair<int, int> game : games){
            string first = possibilities[i][game.first - 1];
            string second = possibilities[i][game.second - 1];
            if((first == "hoof" && second == "scissors") || (first == "paper" && second == "hoof") || (first == "scissors" && second == "paper")){
                count++;
            }
        }
        if (count > bigcount){
            bigcount = count;
        }
    }
    fout << bigcount;
}