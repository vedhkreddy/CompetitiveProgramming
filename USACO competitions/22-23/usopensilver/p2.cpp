#include <bits/stdc++.h>
using namespace std;

map<int, map<int, vector<int>>> v;
map<int, map<int, int>> m;
int biggest[200005];

int main(){
    int c, n;
    cin >> c >> n;
    vector<string> x;
    for (int i = 0; i < n; i++){
        string s; cin >> s; x.push_back(s);
    }
    for (int i = 0; i < n; i++){
        int counter = 0;
        for (char c : x[i]){
            if (c == 'G'){
                v[counter][0].push_back(i);
            }
            else{
                v[counter][1].push_back(i);
            }
            counter++;
        }
    }
    
    for (int i = 0; i < n; i++){
        for (int i : v[i][0]){
            for (int j : v[i][1]){
                m[i][j]++;
                m[j][i]++;
                if (m[i][j] > biggest[i]){
                    biggest[i] = m[i][j];
                }
                 if (m[j][i] > biggest[j]){
                    biggest[j] = m[j][i];
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << biggest[i] << endl;
    }
}