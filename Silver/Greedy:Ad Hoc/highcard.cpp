#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int arraycounter[500000];
int main(){
    ifstream fin("highcard.in");
    ofstream fout("highcard.out");
    int n;
    fin >> n;
    vector<int> elsie;
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        elsie.push_back(a);
        arraycounter[a] = 1;
    }
    vector<int> bessie;
    for (int i = 1; i <= n*2; i++){
        if (arraycounter[i] == 0){
            bessie.push_back(i);
        }
    }
    sort(elsie.begin(), elsie.end(), greater<int>());
    sort(bessie.begin(), bessie.end(), greater<int>());
    int count = 0;
    for (int i = n-1; i >= 0; i--){
        if (bessie[i] > elsie[elsie.size() - 1]){
            elsie.pop_back();
            count++;
        }
    }
    fout << count;
}