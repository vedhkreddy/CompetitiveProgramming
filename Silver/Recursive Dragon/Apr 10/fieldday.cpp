#include <bits/stdc++.h>
using namespace std;

int32_t main(){
    //ifstream cin("test.txt");
    //generate bits
    int c, n; cin >> c >> n;
    vector<int> dists(1<<c, -1);
    queue<int> nodes;
    vector<int> teams;

    for (int i = 0; i < n; i++){
        string sequence; cin >> sequence;
        int org = 0; int reverse = 0;
        for (int j = 0; j < c; j++){
            org = (sequence[j] == 'G') + 2*org;
            reverse = (sequence[j] == 'H') + 2*reverse;
        }
        nodes.push(reverse);
        dists[reverse] = 0;
        teams.push_back(org);
    }

    while(nodes.size() > 0){
        int node = nodes.front(); nodes.pop();
        for (int i = 0; i < c; i++){
            int modified = node ^ (1<<i);
            if (dists[modified] == -1){
                nodes.push(modified);
                dists[modified] = dists[node] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++){
        cout << (c - dists[teams[i]]) << endl;
    }
}