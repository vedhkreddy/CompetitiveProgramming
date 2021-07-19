#include <iostream>
#include <fstream>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=568
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");
    int N, M;
    fin >> N >> M;
    pair<int, int> bessiepairs[M];
    pair<int, int> roadpairs[N];
    int bessie[100];
    int road[100];
    for(int i = 0; i < N; i++){
        int a, b;
        fin >> a >> b;
        roadpairs[i] = make_pair(a, b);
    }
    for(int i = 0; i < M; i++){
        int a, b;
        fin >> a >> b;
        bessiepairs[i] = make_pair(a, b);
    }

    int startpoint = 0;
    for(int i = 0; i < N; i++){
        for(int j = startpoint; j < startpoint + roadpairs[i].first; j++){
            road[j] = roadpairs[i].second;            
        }
        startpoint += roadpairs[i].first;
    }
    startpoint = 0;
    for(int i = 0; i < M; i++){
        for(int j = startpoint; j < startpoint + bessiepairs[i].first; j++){
            bessie[j] = bessiepairs[i].second;            
        }
        startpoint += bessiepairs[i].first;
    }

    int bigcount = 0;
    for(int i = 0; i < 100; i++){
        int count = bessie[i] - road[i];
        if (bigcount < count){
            bigcount = count;
        }
    }

    fout << bigcount;
}