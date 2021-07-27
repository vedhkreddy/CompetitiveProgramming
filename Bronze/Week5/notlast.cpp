#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


string solve(vector<int> numlist, map<string, int> name2number){
    vector<string> namelist;
    if (numlist.size() == 1){
        numlist.push_back(numlist[0]);
    }
    if(1 == 1){
        for (auto const& x : name2number){
            if(x.second == numlist[1]){
                namelist.push_back(x.first);
            }
        }
    }
    if(namelist.size() > 1){
        return "Tie";
    }
    else{
        return namelist[0];
    }
}


int main(){
    //http://usaco.org/indexphp?page=viewproblem2&cpid=687
    ifstream fin("notlast.in");
    ofstream fout("notlast.out");
    int N;
    fin >> N;
    vector<int> numlist;
    map<string, int> name2number;
    for(int i = 0; i < N; i++){
        string a;
        int b;
        fin >> a >> b;
        try{
            name2number[a] += b;
                for(int i : numlist){
                    cout << i << endl;;
                }
        }
        catch(int e){
            name2number[a] = b;
        }
    }
    for (auto const& x : name2number){
        numlist.push_back(x.second);
    }
    sort( numlist.begin(), numlist.end() );
    numlist.erase( unique( numlist.begin(), numlist.end() ), numlist.end() );
    string sol = solve(numlist, name2number);
    fout << sol;
}