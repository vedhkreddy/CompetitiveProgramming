#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ifstream fin("traffic.in");
    ofstream fout("traffic.out");
    int N;
    fin >> N;
    int miles[N][3];
    for (int i = 0; i < N; i++){
        string a;
        fin >> a;
        if (a.compare("on") == 0){
            miles[i][0] = 1;
        }
        else if (a.compare("off") == 0){
            miles[i][0] = -1;
        }
        else{
            miles[i][0] = 0;
        }
        fin >> miles[i][1] >> miles[i][2];
    }
    pair<int, int> flow;
    bool cur = true;
    for (int i = N-1; i > -1; i--){
        if ((miles[i][0] == -1 || miles[i][0] == 1) && cur == true){
            continue;
        }
        else if (miles[i][0] == 0 && cur == true){
            flow.first = miles[i][1];
            flow.second = miles[i][2];
            cur = false;
            continue;
        }
        if (miles[i][0] == 1){
            flow.first -= miles[i][2];
            flow.second -= miles[i][1];
        }
        else if (miles[i][0] == -1){
            flow.first += miles[i][1];
            flow.second += miles[i][2];
        }
        else{
            flow.first = max(flow.first, miles[i][1]);
            flow.second = min(flow.second, miles[i][2]);
        }
    }
    if (flow.first < 0){
        flow.first = 0;
    }
    if (flow.second < 0){
        flow.second = 0;
    }
    fout << flow.first << ' ' << flow.second << endl;
    cur = true;
    for (int i = 0; i < N; i++){
        if ((miles[i][0] == -1 || miles[i][0] == 1) && cur == true){
            continue;
        }
        else if (miles[i][0] == 0 && cur == true){
            flow.first = miles[i][1];
            flow.second = miles[i][2];
            cur = false;
            continue;
        }
        if (miles[i][0] == 1){
            flow.first += miles[i][1];
            flow.second += miles[i][2];
        }
        else if (miles[i][0] == -1){
            flow.first -= miles[i][2];
            flow.second -= miles[i][1];
        }
        else{
            flow.first = max(flow.first, miles[i][1]);
            flow.second = min(flow.second, miles[i][2]);
        }
    }
    if (flow.first < 0){
        flow.first = 0;
    }
    if (flow.second < 0){
        flow.second = 0;
    }
    fout << flow.first << ' ' << flow.second << endl;
}