#include <iostream>
#include <fstream>
using namespace std;

int grass[2000][2000];
int main(){
    //usaco.org/index.php?page=viewproblem2&cpid=593
    ifstream fin("mowing.in");
    ofstream fout("mowing.out");
    int N;
    fin >> N;
    pair<char, int> directions[N];
    pair<int, int> point = make_pair(1000, 1000);
    int time = 0;
    for(int i = 0; i < N; i++){
        char a;
        int b;
        fin >> a >> b;
        directions[i] = make_pair(a,b);
    }
    double bigtime = 5e10;  
    for (int i = 0; i < N; i++){
        for(int j = 0; j < directions[i].second; j++){
            if (directions[i].first == 'N'){
                point.second++;
            }
            else if(directions[i].first == 'S'){
                point.second--;
            }
            else if(directions[i].first == 'E'){
                point.first++;
            }
            else{
                point.first--;
            }
            time++;
            if(grass[point.first][point.second] != 0){
                if (time - grass[point.first][point.second] < bigtime){
                    bigtime = time - grass[point.first][point.second];
                }
            }

            grass[point.first][point.second] = time;
        }
    }
    if (bigtime == 5e10){
        bigtime = -1;
    }
    fout << bigtime;
}