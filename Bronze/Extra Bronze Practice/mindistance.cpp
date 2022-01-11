#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    //ifstream cin("this.in");
    long long t;
    cin >> t;
    vector<vector<long long>> depotlists;
    long long klist[t];
    for (long long i = 0; i < t; i++){
        long long n, k;
        cin >> n >> k;
        klist[i] = k;
        vector<long long> curlist;
        for (long long j = 0; j < n; j++){
            long long a;
            cin >> a;
            curlist.push_back(a);
        }
        depotlists.push_back(curlist);
    }

    for (long long i = 0; i < depotlists.size(); i++){
        vector<long long> curlist = depotlists[i];
        sort (curlist.begin(), curlist.end());
        vector<long long> neglist;
        vector<long long> poslist;
        vector<long long> first;
        vector<long long> second;
        for (long long j : curlist){
            if (j < 0){
                neglist.push_back(j);
            }
            else{
                poslist.push_back(j);
            }
        }
        long long n = curlist.size();
        if (-1 * curlist[0] > curlist[n-1] && neglist.size() != 0){
            first = neglist;
            second = poslist;
            sort (first.begin(), first.end(), greater<long long>());
        }
        else{
            first = poslist;
            second = neglist;
            sort (second.begin(), second.end(), greater<long long>());
        }
        long long count = 0;
        
        long long curhave = klist[i];
        long long z = first.size();
        for (long long f : first){
            long long z = f;
        }
        for (long long j = (z % curhave) - 1; j < z; j += curhave){
            if (j == -1){
                j += curhave;
            }
            if (j == z - 1){
                if (first[0] < 0){
                    count += -1 * (first[j]);
                }
                else{
                    count += first[j];
                }
                continue;
            }
            if (first[0] < 0){
                count += -2 * (first[j]);
            }
            else{
            count += 2 * (first[j]);
            }
        }
        z = second.size();
        for (long long j = (second.size() % curhave) - 1; j < z && second.size() != 0; j += curhave){
            if (j == -1){
                j += curhave;
            }
            if (second[0] < 0){
                count += -2 * (second[j]);
            }
            else{
                count += 2 * (second[j]);
            }
        }
        cout << count << endl;
    }
}