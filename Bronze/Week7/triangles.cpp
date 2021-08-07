#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;

int solve(int N, pair<int, int> cows[]){
    int max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if (i != j && j != k && i != k){
                    if (cows[i].first == cows[j].first && cows[i].second == cows[k].second){
                        int curmax = abs((cows[j].second - cows[i].second) * (cows[k].first - cows[i].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                    if (cows[i].first == cows[k].first && cows[i].second == cows[j].second){
                        int curmax = abs((cows[k].second - cows[i].second) * (cows[j].first - cows[i].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                    if (cows[j].first == cows[i].first && cows[j].second == cows[k].second){
                        int curmax = abs((cows[i].second - cows[j].second) * (cows[k].first - cows[j].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                    if (cows[j].first == cows[k].first && cows[j].second == cows[i].second){
                        int curmax = abs((cows[k].second - cows[j].second) * (cows[i].first - cows[j].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                    if (cows[k].first == cows[i].first && cows[k].second == cows[j].second){
                        int curmax = abs((cows[i].second - cows[k].second) * (cows[j].first - cows[k].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                    if (cows[k].first == cows[j].first && cows[k].second == cows[i].second){
                        int curmax = abs((cows[j].second - cows[k].second) * (cows[i].first - cows[k].first));
                        if (curmax > max){
                            max = curmax;
                        }
                    }
                }
            }
        }
    }
    return max;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1011
    ifstream fin("triangles.in");
    ofstream fout("triangles.out");
    int N;
    fin >> N;
    pair<int, int> cows[N];
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        cows[i] = make_pair(a, b);
    }
    int solution = solve(N, cows);
    fout << solution;
}