#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=591
    //initializating variables
    ifstream fin("promote.in");
    ofstream fout("promote.out");
    vector<int> before;
    int beforetotal = 0;
    vector<int> after;
    int aftertotal = 0;
    vector<int> promotions;
    bool first = true;
    //reading in the lists, and reversing them
    for(int i = 0; i < 8; i++){
        if (first == true){
            int j;
            fin >> j;
            before.push_back(j);
            first = false;
        }
        else{
            int j;
            fin >> j;
            after.push_back(j);
            first = true; 
        }
    }
    reverse(before.begin(), before.end());
    reverse(after.begin(), after.end());

    //updating for new bronze students
    for(int i: before){
        beforetotal += i;
    }
    for(int i: after){
        aftertotal += i;
    }
    before[3] += (aftertotal - beforetotal);

    //simulating all the way from platinum down
    for(int i = 0; i < 4; i++){
        if (before[i] == after[i]){
            continue;
        }
        else{
            before[i+1] -= (after[i] - before[i]);
            promotions.push_back((after[i] - before[i]));
            before[i] = after[i];
        }
    }
    //reversing promotions
    reverse(promotions.begin(), promotions.end());
    //fout
    for(int i: promotions){
        fout << i << endl;
    }
    if(promotions.size() == 0){
        fout << 0 << endl << 0 << endl << 0 << endl;
    }
}