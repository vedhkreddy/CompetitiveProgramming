#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("race.in");
    ofstream fout("race.out");
    int K;
    fin >> K;
    int N;
    fin >> N;
    int Xvalues[N];
    for(int i = 0; i < N; i++){
        
    }
    int curspeed = 1;
    int distance = 1;
    int time = 1;
    while (true){
        if ((curspeed + 2)*(curspeed + 1) / 2 + distance > K){
            break;
        }
        else{
            curspeed++;
            distance += curspeed;
            time++;
        }
    }
    while (distance < K){
        if ((curspeed + 1)*(curspeed) / 2 + distance > K){
            curspeed--;
            distance += curspeed;
            time++;
            continue;
        }
        distance += curspeed;
        time++;
    }
    fout << time;
}