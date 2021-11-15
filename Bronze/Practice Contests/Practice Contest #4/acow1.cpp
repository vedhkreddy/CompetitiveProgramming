#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
using namespace std;

bool check(int index, int given, int citations[]){
    for (int i = 0; i < index; i++){
        if (citations[i] >= index){
            continue;
        }
        if (index-citations[i] == 1 && given > 0){
            given--;
            continue;
        }
        return false;
    }
    return true;
}

int binarysearch(int &least, int &greatest, int citations[], int given) {

    int midpoint = (least + greatest)/2;
    if (least == midpoint) {
        return least;
    } 
    else if (check(midpoint, given, citations)){
        least = midpoint;
    }
    else {
        greatest = midpoint;
    }
    return binarysearch(least, greatest, citations, given);
}

int main(){
    //ifstream cin("acow1.in");
    //http://usaco.org/index.php?page=viewproblem2&cpid=1131
    int N, L;
    cin >> N >> L;
    int citations[N];
    for (int i = 0; i < N; i++){
        cin >> citations[i];
    }
    sort(citations, citations+N, greater<int>());

    int least = 0;
    int greatest = N+1;
    cout << binarysearch(least, greatest, citations, L);
}