#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    //ifstream cin("test.in");
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int x[n];
        for (int j = 0; j < n; j++){
            cin >> x[j];
        }
        vector<int> sequence;
        vector<int> v;
        int p1 = 0;
        int p2 = n-1;
        while (p1 < p2){
            sequence.push_back(x[p1]);
            sequence.push_back(x[p2]);
            p1++;p2--;
        }
        if (p1 == p2){
            sequence.push_back(x[p1]);
        }
        for (int j : sequence){
            cout << j << " ";
        }
        cout << endl;
    }
}