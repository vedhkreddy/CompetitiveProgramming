#include <bits/stdc++.h>
using namespace std;

int maxN = 1003;
char grid[1003][1003];
int good[1003][1003];
int visited[1003][1003];
int n;

int upd = 0;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char dirs[] = {'R', 'L', 'D', 'U'};

bool inbounds(int x, int y){
    return (x >= 0 && x < n && y >= 0 && y < n);
}

void markgood(int x, int y){
    visited[x][y] = 1;
    if (good[x][y] == 0) upd++;
    good[x][y] = 1;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!inbounds(nx, ny)) continue;
        if (visited[nx][ny] == 1) continue;
        if (good[nx][ny] == 1) continue;
        if (grid[nx][ny] == '?') markgood(nx, ny);
        //check if its a dir that you're moving in the correct dir
        if (grid[nx][ny] == 'R' && dy[i] == -1) markgood(nx, ny);
        if (grid[nx][ny] == 'L' && dy[i] == 1) markgood(nx, ny);
        if (grid[nx][ny] == 'U' && dx[i] == 1) markgood(nx, ny);
        if (grid[nx][ny] == 'D' && dx[i] == -1) markgood(nx, ny);
    }
}

int findbad(){
    int bad = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (good[i][j] == 0) bad++;
        }
    }
    return bad;
}

int main(){
    //initialize queries
    cin >> n; int q; cin >> q;
    vector<pair<pair<int, int>, char>> queries;
    for (int i = 0; i < q; i++){
        int a; cin >> a; int b; cin >> b; char c; cin >> c; a--; b--;
        queries.push_back({{a, b}, c});
        grid[a][b] = c;
    }
    //initialize ? marks
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            bool notdir = false;
            for (int k = 0; k < 4; k++){
                if (grid[i][j] == dirs[k]){
                    notdir = true;
                }
            }
            if (!notdir) grid[i][j] = '?';
            //cout << grid[i][j];
        }
        //cout << endl;
    }

    //check which cells are good in the end (they will always be good)
    for (int i = 0; i < n; i++){
        //iterate across rows
        int dx[] = {0, i, i, n-1};
        int dy[] = {i, 0, n-1, i};
        for (int j = 0; j < 4; j++){
            int nx = dx[j]; int ny = dy[j];
            //cout << nx << " " << ny << endl;
            if (visited[nx][ny] == 0 && inbounds(nx, ny)){
                if (grid[nx][ny] == '?') markgood(nx, ny);
                else if (grid[nx][ny] == 'R' && ny == n-1) markgood(nx, ny);
                else if (grid[nx][ny] == 'L' && ny == 0) markgood(nx, ny);
                else if (grid[nx][ny] == 'U' && nx == 0) markgood(nx, ny);
                else if (grid[nx][ny] == 'D' && nx == n-1) markgood(nx, ny);
            }
        }
    }
    
    upd = 0;
    int cur = findbad();
    vector<int> res; res.push_back(findbad());
    //process queries backwards
    for (int i = q-1; i >= 0; i--){
        upd = 0;
        int x = queries[i].first.first;
        int y = queries[i].first.second;
        bool connectedtogood = false;
        grid[x][y] = '?';
        if (x == 0 || x == n-1 || y == 0 || y == n-1){
            upd = 0;
            markgood(x, y);
            cur -= upd;
            res.push_back(cur);
            continue;
        }
        for (int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (inbounds(nx, ny) && good[nx][ny] == 1){
                connectedtogood = true;
            }
        }
        if (connectedtogood == false) {res.push_back(res[res.size() - 1]); continue;}
        upd = 0;
        markgood(x, y);
        //cout << i << endl;
        cur -= upd;
        res.push_back(cur);
    }
    for (int i = q-1; i >= 0; i--){
        cout << res[i] << endl;
    }
    
}