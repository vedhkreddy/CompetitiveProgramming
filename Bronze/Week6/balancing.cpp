#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(pair<int, int> cows[], int N, int B){
    int min = 1000;
    for(int a = 0; a < B; a++){
        for(int b = 0; b < B; b++){
            int quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
            for(int i = 0; i < N; i++){
                if (cows[i].first > a && cows[i].second > b){
                    quadrant1++;
                }
                else if (cows[i].first > a && cows[i].second < b){
                    quadrant2++;
                }
                else if(cows[i].first < a && cows[i].second < b){
                    quadrant3++;
                }
                else{
                    quadrant4++;
                }
            }
            vector<int> quadrants = {quadrant4, quadrant3, quadrant2, quadrant1};
            int max = *max_element(quadrants.begin(), quadrants.end());
            if (max < min){
                min = max;
            }
            b++;
        }
        a++;
    }
    return min;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=617
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int N, B;
    fin >> N >> B;
    pair<int, int> cows[N];
    for(int i = 0; i < N; i++){
        int x, y;
        fin >> x >> y;
        cows[i] = make_pair(x, y);
    }
    int solution = solve(cows, N, B);
    fout << solution;
}