#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

bool inalphabetical(string a, string b){
    vector<string> c;
    c.push_back(a);
    c.push_back(b);
    sort(c.begin(), c.end());
    return a.compare(c[0]) == 0;
}

int main(){
    ifstream fin ("acow2.in");
    int K, N;
    cin >> K >> N;
    string members[N];
    for(int i = 0; i < N; i++){
        cin >> members[i];
    }
    string publications[K][N];
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cin >> publications[i][j];
        }
    }
    vector<pair<string, string>> conditions;
    for(int i = 0; i < K; i++){
        for(int j = 1; j < N; j++){
            string first = publications[i][j];
            bool beforealphabetical = false;
            for (int k = j-1; k >= 0; k--){
                if (inalphabetical(publications[i][k], publications[i][k + 1]) == false || beforealphabetical == true){
                    beforealphabetical = true;
                    conditions.push_back(make_pair(publications[i][k], first));
                }
                else if (inalphabetical(publications[i][k], publications[i][k + 1]) == true){
                    continue;
                }
            }
        }
    }
    map<string, map<string, int>> order;
    for(string s : members){
        for (string b : members){
            order[s][b] = 100;
        }
    }
    for(pair<string, string> p : conditions){
        order[p.first][p.second] = 0;
        order[p.second][p.first] = 1;
    }
    for (string s : members){
        for(string b : members){
            if (s.compare(b) == 0){
                cout << "B";
            }
            else if (order[s][b] == 100){
                cout << "?";
            }
            else{
                cout << order[s][b];
            }
        }
        cout << endl;
    }
}