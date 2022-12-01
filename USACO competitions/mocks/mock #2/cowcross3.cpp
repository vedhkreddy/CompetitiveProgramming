#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <cmath>
using namespace std;

int grid[105][105]; 
int visited[105][105];
int counter;
int sols = 0;
int n, k, r;
vector<pair<int, int>> cows;

void floodfill(int r, int c){
    if ((r < 0 || r >= n || c < 0 || c >= n) || grid[r][c] != 1 || visited[r][c] == 1){
        return;
    }
    visited[r][c] = 1;
    
    floodfill(r, c+1);
    floodfill(r, c-1);
    floodfill(r-1, c);
    floodfill(r+1, c);
}


void cleargraph(){
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            grid[i][j] = 0;
        }
    }
}


void update(){
    for (int i = 0; i < k; i++){
        if (visited[cows[i].first][cows[i].second] == 0){
            sols++;
        }
    }
}


int main(){
    ifstream cin("cowcross3.in");
    cin >> n >> k >> r;
    for (int i = 0; i < r; i++){
        int a, b, c, d; cin >> a >> b >> c >> d;
        a--; b--; c--; d--;
        grid[a][b] = 1;
        grid[c][d] = 1;
    }
    
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        cows.push_back(make_pair(a - 1, b - 1));
    }

    for (int i = 0; i < k; i++){
        cleargraph();
        floodfill(cows[i].first, cows[i].second);
        update();
    }
    
    cout << floor(sols/2);
}