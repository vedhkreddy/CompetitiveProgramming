//break into cases

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
int wall[10000000];
int n;

int solve(int n){
 int ans = 100000000;
    for (int i = 0; i < n - 1; i++) {
        int cur = 0;
        int x = wall[i], y = wall[i + 1];
        if (x < y) {
            swap(x, y);
        }
        int cnt = min(x - y, (x + 1) / 2);
        cur += cnt;
        x -= 2 * cnt;
        y -= cnt;
        if (x > 0 && y > 0) {
            cur += (x + y + 2) / 3;
        }
        ans = min(ans, cur);    
    }

    for (int i = 0; i < n - 2; i++) {
        int cur = 0;
        int x = wall[i], y = wall[i + 2];
        if (x < y) {
            swap(x, y);
        }
        int cnt = (x - y + 1) / 2;
        cur += cnt;
        cur += y;
        ans = min(ans, cur);
    }
    
    sort(wall, wall + n);
    ans = min(ans, (wall[0] + 1) / 2 + (wall[1] + 1) / 2);
    return ans;
}

int main(){
    //ifstream cin("test.in");
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> wall[i];
    }
    cout << solve(n);
}