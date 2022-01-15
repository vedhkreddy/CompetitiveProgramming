#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
using namespace std;

int letters[26];
int main(){
    //ifstream cin("this.in");
    int t;
    cin >> t;
    vector<string> strings;
    vector<set<int>> mlist;
    vector<map<int, int>> mcapacity;
    vector<int> mint;
    for (int i = 0; i < t; i++){
        int n, m;
        cin >> n >> m;
        string x;
        cin >> x;
        strings.push_back(x);
        set<int> cur;
        mint.push_back(m);
        map<int, int> curcapacity;
        for (int j = 0; j < m; j++){
            int a;
            cin >> a;
            if (curcapacity.find(a) == curcapacity.end()){
                curcapacity[a] = 1;
            }
            else{
                curcapacity[a]++;
            }
            cur.insert(a);
        }
        mlist.push_back(cur);
        mcapacity.push_back(curcapacity); 
    }
    for (int i = 0; i < strings.size(); i++){
        int addby = mint[i];
        for (int j = 0; j < strings[i].size(); j++){
            auto iteratorthingy = mlist[i].begin();
            if (*(iteratorthingy) == j){
                addby -= mcapacity[i][*(iteratorthingy)];
                if (mlist[i].size() != 0){
                    mlist[i].erase(iteratorthingy);
                }
            }
            letters[int(strings[i][j] - 97)] += addby;

        }
        for (int j = strings[i].size() - 1; j > -1; j--){
            letters[int(strings[i][j] - 97)] += 1;
        }
        for (int j = 0; j < 26; j++){
            cout << letters[j] << " ";
        }
        cout << endl;
        for (int j = 0; j < 26; j++){
            letters[j] = 0;
        }
    }
}