#include <iostream>
#include <vector>
#include <fstream>
#include <set>
//#include "../../../../DebuggingStuff/prettyprint.hpp"
#include <algorithm>
using namespace std;

int main(){
    //http://www.usaco.org/index.php?page=viewproblem2&cpid=857
    ifstream fin("backforth.in");
    ofstream fout("backforth.out");
    vector<int> first;
    vector<int> second;
    int firstcount = 0;
    int N;
    //fin >> N;
    N = 10;
    for (int i = 0; i < N; i++){
        int a;
        fin >> a;
        firstcount += a;
        first.push_back(a);
    }
    for(int i = 0; i < N; i++){
        int a;
        fin >> a;
        second.push_back(a);
    }
    set<int> values;
    auto original11 = first;
    auto orginal12 = second;
    for (int i = 0; i < first.size(); i++){
        first = original11;
        second = orginal12;
        second.push_back(first[i]);
        first.erase(first.begin() + i);
        auto original21 = first;
        auto original22 = second;
        for (int j = 0; j < second.size(); j++){
            first = original21;
            second = original22;
            first.push_back(second[j]);
            second.erase(second.begin() + j);
            auto original31 = first;
            auto original32 = second;
            for (int k = 0; k < first.size(); k++){
                first = original31;
                second = original32;
                second.push_back(first[k]);
                first.erase(first.begin() + k);
                auto original41 = first;
                auto original42 = second;
                for (int l = 0; l < second.size(); l++){
                    first = original41;
                    second = original42;
                    first.push_back(second[l]);
                    second.erase(second.begin() + l);
                    //cout << first << endl;
                    //cout << second << endl;
                    int count = 0;
                    for (int m : first){
                        count += m;
                    }
                    values.insert(count);
                }
            }
        }
    }
    for (int i : values){
        cout << i << endl;
    }
    fout << values.size();
}