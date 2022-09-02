#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long
int stores[100001][2];
bool departed[100001];
vector<pair<int, int>> weight;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        weight.push_back({0,0});
    }
    weight.push_back({0,0});
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        stores[i+1][0] = a;
        stores[i+1][1] = b;
        weight[a].first += b;
        weight[a].second = a;
    }
    sort(weight.begin(), weight.end());
    ll answer = 0;
    for (pair<int, int> p : weight){
        if (departed[stores[p.second][0]] == false){
            answer += stores[p.second][1];
            departed[p.second] = true;
        }
    }
    cout << answer;
}   