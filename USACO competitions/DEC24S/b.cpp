#include <bits/stdc++.h>
using namespace std;

int good[1002][1002];
char grid[1002][1002];
int visited[1002][1002];
int n;

int countinitial = 0;

void floodfillinitial(int x, int y){
    if (x < 0 || x > n-1 || y < 0 || y > n-1 || grid[x][y] != '?' || visited[x][y] == 1){
        return;
    }
    visited[x][y] = 1;
    good[x][y] = 1;
    floodfillinitial(x, y+1);
    floodfillinitial(x+1,y);
    floodfillinitial(x-1,y);
    floodfillinitial(x,y-1);
}

void floodfillinitial2(int x, int y){
    if (x < 0 || x > n || y < 0 || y > n || visited[x][y] == 1){
        return;
    }
    visited[x][y] = 1;
    if (grid[x][y] == 'R' || grid[x][y] == 'L' || grid[x][y] == 'U' || grid[x][y] == 'D'){
        int nextx = x, nexty = y;
        if (grid[x][y] == 'R') nexty++;
        else if (grid[x][y] == 'L') nexty--;
        else if (grid[x][y] == 'U') nextx--;
        else if (grid[x][y] == 'D') nextx++;
        if (nextx < 0 || nextx > n || nexty < 0 || nexty > n) {
            good[x][y] = 1;
            return;
        }
        if (good[nextx][nexty] == 1){
            good[x][y] = 1;
        } 
        else {
            floodfillinitial2(nextx, nexty);
            if (good[nextx][nexty] == 1){
                good[x][y] = 1;
            }
        }
    } 
    else {
        int nextx = x, nexty = y+1;
        if (nextx < 0 || nextx > n || nexty < 0 || nexty > n) {
            good[x][y] = 1;
            return;
        }
        if (good[nextx][nexty] == 1){
            good[x][y] = 1;
        } 
        else {
            floodfillinitial2(nextx, nexty);
            if (good[nextx][nexty] == 1){
                good[x][y] = 1;
            }
        }
        nextx = x; nexty = y-1;
        if (nextx < 0 || nextx > n || nexty < 0 || nexty > n) {
            good[x][y] = 1;
            return;
        }
        if (good[nextx][nexty] == 1){
            good[x][y] = 1;
        } 
        else {
            floodfillinitial2(nextx, nexty);
            if (good[nextx][nexty] == 1){
                good[x][y] = 1;
            }
        }
        nextx = x+1; nexty = y;
        if (nextx < 0 || nextx > n || nexty < 0 || nexty > n) {
            good[x][y] = 1;
            return;
        }
        if (good[nextx][nexty] == 1){
            good[x][y] = 1;
        } 
        else {
            floodfillinitial2(nextx, nexty);
            if (good[nextx][nexty] == 1){
                good[x][y] = 1;
            }
        }
        nextx = x-1; nexty = y;
        if (nextx < 0 || nextx > n || nexty < 0 || nexty > n) {
            good[x][y] = 1;
            return;
        }
        if (good[nextx][nexty] == 1){
            good[x][y] = 1;
        } 
        else {
            floodfillinitial2(nextx, nexty);
            if (good[nextx][nexty] == 1){
                good[x][y] = 1;
            }
        }
    }
}

void floodfill3(int x, int y) {
    if (x < 0 || x > n || y < 0 || y > n) return;
    if (visited[x][y] == 1) return;
    if (good[x][y] == 1) {
        visited[x][y] = 1;
        return;
    }
    grid[x][y] = '?';
    visited[x][y] = 1;
    good[x][y] = 1;
    countinitial--;

    if (grid[x][y] == '?') {
        if (x+1 < n && grid[x+1][y] == '?') floodfill3(x+1, y);
        if (x-1 >= 0 && grid[x-1][y] == '?') floodfill3(x-1, y);
        if (y+1 < n && grid[x][y+1] == '?') floodfill3(x, y+1);
        if (y-1 >= 0 && grid[x][y-1] == '?') floodfill3(x, y-1);
    }

    if (x+1 < n && grid[x+1][y] == 'U') floodfill3(x+1, y);
    if (x-1 >= 0 && grid[x-1][y] == 'D') floodfill3(x-1, y);
    if (y-1 >= 0 && grid[x][y-1] == 'R') floodfill3(x, y-1);
    if (y+1 < n && grid[x][y+1] == 'L') floodfill3(x, y+1);
}



int main(){
    //ifstream cin("inp.in");
    int q; cin >> n >> q;
    vector<vector<int>> queries;
    for (int i = 0; i < q; i++){
        int r; int c; char t; cin >> r >> c >> t;
        grid[r-1][c-1] = t;
        r--; c--;
        queries.push_back({r, c, t});
    }
    reverse(queries.begin(), queries.end());
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] != 'R' && grid[i][j] != 'U' && grid[i][j] != 'D' && grid[i][j] != 'L'){
                grid[i][j] = '?';
            }
            //cout << grid[i][j];
        }
        //cout << endl;
    }

    for (int i = 0; i < n; i++){
        if (visited[i][0] == 0 && grid[i][0] == '?'){
            floodfillinitial(i, 0);
        }
        if (visited[i][n-1] == 0 && grid[i][n-1] == '?'){
            floodfillinitial(i, n-1);
        }
        if (visited[0][i] == 0 && grid[0][i] == '?'){
            floodfillinitial(0, i);
        }
        if (visited[n-1][i] == 0 && grid[n-1][i] == '?'){
            floodfillinitial(n-1, i);
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (grid[i][j] == 'R' || grid[i][j] == 'L' || grid[i][j] == 'U' || grid[i][j] == 'D') {
                floodfillinitial2(i, j);
            }
        }
    }

    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (good[i][j] == 0) countinitial++;
            //cout << good[i][j];
        }
        //cout << endl;
    }
    //countinitial = n*n - countinitial;
   // cout << countinitial << endl;

    //now we have to update the grid in reverse order and see what happens (do floodfills to make sure)
    //once something is removed, first check if its a good one(if it is, then just remove it and nothing changes)
    //if not, then check if its connected to any bad ?'s or directions
    //if it's connected to anything good, first floodfill on any bad ? that it's connected to and mark them all as good
    //then if its connected to any bad letters, do a reverse floodfill on the letters if they flow into the current thing cause it's marked as good
    //two floodfills in total
    vector<int> res;
    res.push_back(countinitial);
    for (int i = 0; i < q-1; i++){
        vector<int> quer = queries[i];
        int x = quer[0]; int y = quer[1];
        grid[x][y] = '?';
        floodfill3(x, y);
        res.push_back(countinitial);
    }
    reverse(res.begin(), res.end());
    for (int i : res){
        cout << i << endl;
    }
    /*
    D?DL
    LRRD
    D??D
    RULL
    1100
    1000
    0000
    0000
    */
}
