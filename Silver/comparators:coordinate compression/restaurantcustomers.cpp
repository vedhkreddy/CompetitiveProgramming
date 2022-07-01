#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

vector<pair<int, int>> intervals;
vector<int> sorting;
int arr[10000000];
int pref[10000000];
map<long long, long long> place;
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        pair<int, int> cur;
        cin >> cur.first >> cur.second;
        intervals.push_back(cur);
        sorting.push_back(cur.first);
        sorting.push_back(cur.second);
    }
    sort(sorting.begin(), sorting.end());
    int size = sorting.size();
    for (int i = 0; i < size; i++){
        place[sorting[i]] = i+1;
    }
    for (pair<int, int> p : intervals){
        p.first = place[p.first];
        p.second = place[p.second];
        arr[p.first]++;
        arr[p.second]--;
    }
    int max = 0;
    for (int i = 1; i < (2*n)+1; i++){
        pref[i] = pref[i-1] + arr[i];
        if (pref[i] > max){
            max = pref[i];
        }
    }
    cout << max << endl;

    
}