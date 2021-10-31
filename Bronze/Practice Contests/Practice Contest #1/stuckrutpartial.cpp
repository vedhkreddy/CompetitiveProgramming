#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1060
    int N;
    cin >> N;
    int cows[N][6];
    int id = 0;
    for(int i = 0; i < N; i++){
        char d;
        cin >> d;
        if (d == 'E'){
            cows[i][1] = 1;
        }
        else{
            cows[i][1] = 0;
        }
        cin >> cows[i][2];
        cin >> cows[i][3];
        cows[i][0] = id;
        cows[i][4] = 0;
        cows[i][5] = 0;
        id++;
    }
    vector<pair<int, int>> alreadypassed;
    for(int c = 0; c < 1000; c++){
        vector<pair<int, int>> alreadypassed1 = alreadypassed;
        for (int i = 0; i < N; i++){
            if (cows[i][5] == 1){
                continue;
            }
            int x = cows[i][2];
            int y = cows[i][3];
            if (cows[i][1] == 0){
                y++;
            }
            else{
                x++;
            }
            for(pair<int, int> p : alreadypassed){
                if (p.first == x && p.second == y){
                    cows[i][5] = 1;
                    break;
                }
            }
            if (cows[i][5] != 1){
                cows[i][4]++;
                cows[i][2] = x;
                cows[i][3] = y;
                alreadypassed1.push_back(make_pair(x, y));
            }
        }
        alreadypassed = alreadypassed1;
    }
    for(int i = 0; i < N; i++){
        if (cows[i][5] == 1){
            cout << cows[i][4] + 1 << endl;
        }
        else{
            cout << "Infinity" << endl;
        }
    }
}