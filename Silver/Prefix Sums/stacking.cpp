#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

int toadd[1000001];
vector<int> stacks;
int main(){
    ifstream fin("stacking.in");
    ofstream fout("stacking.out");
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++){
        int a, b;
        cin >> a >> b;
        toadd[a]++;
        toadd[b+1]--;
    }
    for (int i = 0; i < n; i++){
        if (i == 0){
            stacks.push_back(toadd[i+1]);
        }
        else{
            stacks.push_back(toadd[i+1] + stacks[i-1]);
        }
    }
    sort(stacks.begin(), stacks.end());
    cout << stacks[n/2];
}