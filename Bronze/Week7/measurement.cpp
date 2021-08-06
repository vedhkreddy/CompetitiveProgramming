#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int solve(map<int, vector<string>> changes, map<string, int> milk, int N){
    vector<string> board = {};
    int count = 0;
    for(auto const& x : changes){
        vector<string> curboard;
        int magnitude = (int)x.second[1][1] - 48;
        if (x.second[1][0] == '-'){
            milk[x.second[0]] -= magnitude;
        }
        else{
            milk[x.second[0]] += magnitude;
        }
        vector<int> measurements = {milk["Bessie"], milk["Elsie"], milk["Mildred"]};
        int max = *max_element(measurements.begin(), measurements.end());
        if (milk["Bessie"] == max){
            curboard.push_back("Bessie");
        }
        if (milk["Mildred"] == max){
            curboard.push_back("Mildred");
        }
        if (milk["Elsie"] == max){
            curboard.push_back("Elsie");
        }
        if (board != curboard){
            board = curboard;
            count++;
        }
    }
    return count;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=761
    ifstream fin("measurement.in");
    ofstream fout("measurement.out");
    int N;
    fin >> N;
    map<int, vector<string>> changes;
    for (int i = 0; i < N; i++){
        int a;
        string b, c;
        fin >> a >> b >> c;
        changes[a] = {b, c};
    }
    map<string, int> milk;
    milk["Bessie"] = 7;
    milk["Elsie"] = 7;
    milk["Mildred"] = 7;
    int solution = solve(changes, milk, N);
    fout << solution;
}