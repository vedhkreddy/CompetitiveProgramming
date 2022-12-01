#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    ifstream cin("helpcross.in");
    ofstream cout("helpcross.out");
    int c, n;
    cin >> c >> n;
    multiset<int> chickens;
    for(int i = 0; i < c; i++){
        int a; cin >> a; chickens.insert(a);
    }
    vector<pair<int, int>> cows;
    for (int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        cows.push_back(make_pair(b, a));
    }
    sort(cows.begin(), cows.end());
    int counter = 0;
    for (int i = 0; i < n; i++){
        auto chicken1 = chickens.lower_bound(cows[i].second);
        if (chicken1 != chickens.end() && *chicken1 <= cows[i].first) {
            counter++;
            chickens.erase(chicken1);
        }
    }
    cout << counter;
}