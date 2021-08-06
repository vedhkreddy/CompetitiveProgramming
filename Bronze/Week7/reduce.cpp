#include <iostream>
#include <fstream>
using namespace std;

int solve(pair<int, int> cows[], int biggest[4], int N){
    int minarea = 40000 * 40000;
    for (int i = 0; i < N; i++){
        if (cows[i].first == biggest[0] || cows[i].first == biggest[1] || cows[i].second == biggest[2] || cows[i].second == biggest[3]){
            int biggest1[4] = {40001, 0, 40001, 0};
            for (int j = 0; j < N; j++){
                if (cows[i] == cows[j]){
                    continue;
                }
                if (cows[j].first < biggest1[0]){
                    biggest1[0] = cows[j].first;
                }
                if (cows[j].first > biggest1[1]){
                    biggest1[1] = cows[j].first;
                }
                if (cows[j].second < biggest1[2]){
                    biggest1[2] = cows[j].second;
                }
                if (cows[j].second > biggest1[3]){
                    biggest1[3] = cows[j].second;
                }
            }
            int curminarea = (biggest1[1] - biggest1[0]) * (biggest1[3] - biggest1[2]);
            if (curminarea < minarea){
                minarea = curminarea;
            }          
        }
    }
    return minarea;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=641
    ifstream fin("reduce.in");
    ofstream fout("reduce.out");
    int N;
    fin >> N;
    pair<int, int> cows[N];
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        cows[i] = make_pair(a, b);
    }
    int biggest[4] = {40001, 0, 40001, 0};
    for (int i = 0; i < N; i++){
        if (cows[i].first < biggest[0]){
            biggest[0] = cows[i].first;
        }
        if (cows[i].first > biggest[1]){
            biggest[1] = cows[i].first;
        }
        if (cows[i].second < biggest[2]){
            biggest[2] = cows[i].second;
        }
        if (cows[i].second > biggest[3]){
            biggest[3] = cows[i].second;
        }
    }

    int solution = solve(cows, biggest, N);
    fout << solution;
}