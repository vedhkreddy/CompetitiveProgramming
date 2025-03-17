/*
first, find all of the ones that already match and then add the n(n+1)/2 to the left and right of it
then go into the operations

only process the ones to the left of it, reverse, and then do it again
for the ones that are to the left of it, create a map, map stores the type

for each type in the map there is a vector, which consists of the position in the list

for each one, create a prefix sum

1) do a binary search to find the last position not ahead of the current value
2) do a binary search to find the last position who's position is not greater than the distance from the current value to the end

add the prefix sum UP to the position found in the second binary search

add the value of the distance from the current value to the end times the value of the first binary serach - the value of the second binary search

should cover all of the cases
*/


#include <bits/stdc++.h>
using namespace std;

int n;
int a[500000];
int b[500000];

//find first less than or equal

//remember to not overcount the middle one
int count(){
    int res = 0;
    map<int, pair<vector<int>, vector<int>>> m;
    set<int> vals;
    for (int i = 0; i < n; i++){
        m[b[i]].first.push_back(i);
        vals.insert(b[i]);
    }
    for (const int &j : vals){
        m[j].second.push_back(0);
        //cout << endl;
        for (int k = 0; k < m[j].first.size(); k++){
            m[j].second[k+1] = m[j].second[k] + m[j].first[k];
        }
    }
    for (int i = 0; i < n; i++){
        int x = a[i];
        //binary serach to find the last value not ahead of the current value in b[i]
        vector<int> r = m[x].first;
        auto it = upper_bound(r.begin(), r.end(), i);
        int alldistance = 0;
        if (it == r.end()){
            if (r.size() == 0){
                continue;
            }
            it--;
            alldistance = *it;
        }
        if (*it == i){
            alldistance = i;
        }
        if (*it > i){
            if (it != r.begin()){
                it--;
                alldistance = *it;
            }
        }

        // 1 2 3 4 6 5 6 7 8 9 10
        int greaterdistance = 0;
        it = lower_bound(r.begin(), r.end(), n-i);
        if (it == r.end() || *it > i){
            greaterdistance = alldistance;
        }
        cout << alldistance << " " << greaterdistance << endl;
        res += m[x].second[alldistance];
        res += (n-i-1) * (alldistance - greaterdistance);
    }
    return res;
}


int main(){
    ifstream cin("test.in");
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++){
        //cout << a[i] << " " << b[i] << endl;
        if (a[i] == b[i]){
            //cout << "here" << endl;
            res += ((i * (i+1)) / 2);
            res += (((n-i-1) * (n-i)) / 2);
        }
    }
    map<int, pair<vector<int>, vector<int>>> m;
    set<int> vals;
    for (int i = 0; i < n; i++){
        m[b[i]].first.push_back(i+1);
        vals.insert(b[i]);
    }
    for (const int &j : vals){
        m[j].second.push_back(0);
        for (int k = 0; k < m[j].first.size(); k++){
            m[j].second[k+1] = m[j].second[k] + m[j].first[k];
        }
    }
    res += count();
    reverse(a, a+n);
    //cout <<res << endl;
    res += count();
    cout << res << endl;
}  