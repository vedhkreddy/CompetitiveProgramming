#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

bool check(vector<int> first, vector<int> second, int N){
    for(int i = 0; i < N; i++){
        if (first[i] != second[i]){
            return false;
        }
    }
    return true;
}


int solve(int N, vector<int> goal){
    vector<int> order = goal;
    sort(goal.begin(), goal.end());
    int time = 0;
    while(check(order, goal, N) != true){
        if (order[0] > order[N - 1]){
            order.insert(order.end(), order[0]);
            order.erase(order.begin());
            time++;
            continue;
        }

        for (int i = N-2; i > -1; i--){
            if (order[i] > order[i + 1] || order[i] < order[0]){
                int tmp = order[0];
                order.insert(order.begin() + i + 1, tmp);
                order.erase(order.begin());
                time++;
                break;
            }
        }
    }
    return time;
}   

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=892
    ifstream fin("sleepy.in");
    ofstream fout("sleepy.out");
    int N;
    fin >> N;
    vector<int> goal;
    for (int i = 0; i < N; i++){
        int a;
        fin >> a;
        goal.push_back(a);
    }
    int solution = solve(N, goal);
    fout << solution;
}