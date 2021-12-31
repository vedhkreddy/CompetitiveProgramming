#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=964
    ifstream fin("whereami.in");
    ofstream fout("whereami.out");
    int N;
    fin >> N;
    char mailboxes[N];
    for(int i = 0; i < N; i++){
        fin >> mailboxes[i];
    }
    for(int length = 1; length <= N; length++){
        vector<vector<char>> patterns;
        set<vector<char>> patternset;
        for(int i = 0; i < N - length + 1; i++){
            vector<char> pattern;
            for(int indexposition = i; indexposition < i + length; indexposition++){
                pattern.push_back(mailboxes[indexposition]);
            }
            patterns.push_back(pattern);
            patternset.insert(pattern);
        }
        if (patterns.size() == patternset.size()){
            fout << length;
            return 0;
        } 
    }
}