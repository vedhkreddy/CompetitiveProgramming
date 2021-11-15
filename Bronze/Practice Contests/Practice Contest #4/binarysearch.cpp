#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int binarysearch(vector<int> v, int i, int *least, int *greatest) {
    if (abs(*(least) - *(greatest)) == 1 || *(least) == *(greatest)){
        return *greatest;
    }
    else{
        int midpoint = (*least + *greatest)/2;
        if (i > v[midpoint]){
            *(least) = midpoint;
        }
        else{
            *(greatest) = midpoint;
        }
        return binarysearch(v, i, least, greatest);
    }
}

int main(){
    vector<int> v = {1, 6, 2, 3, 6, 23, 6, 3, 3, 4};
    sort (v.begin(), v.end());

    int least = 0;
    int greatest = v.size();
    cout << binarysearch(v, 7, &least, &greatest) <<endl;
}