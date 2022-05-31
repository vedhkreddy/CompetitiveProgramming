#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int stores[100001][2];
bool departed[100001];
vector<vector<int>> weight;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        weight.push_back({0,0});
    }
    weight.push_back({0,0,0});
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        stores[i+1][0] = a;
        stores[i+1][1] = b;
        weight[a][0] += b;
        weight[a][1] = a;
        weight[a][2] = i+1;
    }
    ll answer = 0;
    for (int i = 0; i < n; i++){
        int highestreward = 0;
        pair<int, int> highestpair = make_pair(0,0);
        for (vector<int> v : weight){
            if (departed[v[1]] == false && stores[p.second][1] > highestreward){
                highestreward = p.first;
                highestpair = p;
            }   
            else if (departed[p.second] == true && (stores[p.second][1] - weight[p.second-1].first) > highestreward){
                highestreward = p.first;
                highestpair = p;
            }
        }
        
        answer += stores[p.second][1];

    }
    cout << answer;
}   