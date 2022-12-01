#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int bsearch(int a, vector<int> v){
    auto x = lower_bound(v.begin(), v.end(), a);
    auto y = x;
    y--;
    //cout << *(v.begin()) << endl;
    int al = *x;
    int als = *y;
    if (x == v.begin()){
        return *x;
    }
    else if (abs(*x - a) < abs((*y - a))){
        return *x;
    }
    else{
        return *y;
    }
}

int slowswearch(int a, vector<int> v){
    int ans;
    int diff = 10000000;
    for (int i : v){
        if (abs(i - a) < diff){
            ans = i; diff = abs(i - a);
        }
    }
    return ans;
}

int execute(vector<int> v){
    for (int j = 0; j < 100000; j++){
    for (int i = 0; i < 10; i++){
        v.push_back(rand() % 10);
    }
    int b = 10000;
    sort(v.begin(), v.end());
    if (bsearch(b, v) != slowswearch(b, v)){
        cout << "bad" << endl;
        cout << "num: " << b << endl;
        for (int i : v){
            cout << i << endl;
        }
        cout << "bsearch: " << bsearch(b, v) << " slowsearch: " << slowswearch(b, v) << endl;
        return 0;
    }
    }
    return 1;
}

int main(){
    vector<int>v;
    execute(v);
    
}