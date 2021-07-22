#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void solve(string genome1, string genome2, int min){
    vector<int> differences1;
    vector<int> differences2;
    for(int i = 0; i < min; i++){
        if (genome1[i] != genome2[i]){
            differences1.push_back(genome1[i]);
            differences2.push_back(genome2[i]);
        }
    }
    reverse(differences2.begin(), differences2.end());
    if(differences1.size() > 2){
        cout << "NO" << endl;
    }
    else if(differences2 == differences1){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

int main(){
    //https://codeforces.com/problemset/problem/186/A
    string a, b;
    cin >> a >> b;
    if (a.size() != b.size()){
        cout << "NO" << endl;;
    }
    else{
        solve(a, b, a.size());
    }
}
