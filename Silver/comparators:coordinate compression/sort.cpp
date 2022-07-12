#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main(){
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int n;
    fin >> n;
    vector<int> list;
    vector<int> list1;
    map<int, int> m;
    for (int i = 0; i < n; i++){
        int a; fin >> a;
        list.push_back(a);
        list1.push_back(a);
    }
    sort(list1.begin(), list1.end());
    for (int i = 0; i < n; i++){
        m[list1[i]] = i;
    }
    int max = 0;
    for (int i = 0; i < n; i++){
        if (i - m[list[i]] > max){
            max = i - m[list[i]];
        }
    }
    fout << max + 1;
}