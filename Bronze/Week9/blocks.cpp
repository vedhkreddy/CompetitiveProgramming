#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

map<char, int> start(){
    map<char, int> returnmap;
    for(char i = 'a'; i <= 'z'; i++){
        returnmap[i] = 0;
    }
    return returnmap;
}

map<char, int> merge(map<char, int> first, map<char, int> second, int which){
    map<char, int> returnmap = first;
    for(auto const &x : second){
        if (which == 0 && returnmap[x.first] < x.second){
            returnmap[x.first] = x.second;
        }
        else if (which == 1){
            returnmap[x.first] += x.second;
        }
    }
    return returnmap;
}

map<char, int> find(string first){
    map<char, int> returnmap = start();
    for(char c : first){
        returnmap[c]++;
    }
    return returnmap;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=664
    ifstream fin("blocks.in");
    ofstream fout("blocks.out");
    int N;
    fin >> N;
    vector<pair<string, string>> words;
    //start initializes every letter to zero
    map<char, int> final = start();
    for(int i = 0; i < N; i++){
        string a, b;
        fin >> a >> b;
        words.push_back(make_pair(a, b));
    }
    for(pair<string, string> p : words){
        map<char, int> map1 = find(p.first);
        map<char, int> map2 = find(p.second);
        //merge by greatest
        map<char, int> map3 = merge(map1, map2, 0);
        //merge by adding
        final = merge(final, map3, 1);
    }
    for(auto const &x : final){
        fout << x.second << endl;
    }
}