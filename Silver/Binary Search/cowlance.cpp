#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

vector<int> coworder;

int isgood(int k, int n){
    priority_queue<int, vector<int>, greater<int>> pq;
    int curindex = k-1;
    int max = -1;
    for(int i = 0; i < k; i++){
        pq.push(coworder[i]);
        if (coworder[i] > max){
            max = coworder[i];
        }
    }
    if (k == n){
        return max;
    }
    int cur;
    while(pq.size() != 0){
        curindex++;
        int out = pq.top();
        pq.pop();
        if (curindex < n){
            pq.push(coworder[curindex] + out);
            cur = coworder[curindex] + out;
        }
        else{
            cur = out;
        }
    }
    return cur;
}

int search(int lo, int n, int t){
    int hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (isgood(mid, n) <= t){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    return lo; 
}

int main(){
    ifstream fin("cowdance.in");
    ofstream fout("cowdance.out");
    int n, t;
    fin >> n >> t;
    if (n == 1){
        fout << 1;
        return 0;
    }
    for (int i = 0; i < n; i++){
        int a;
        fin >> a;
        coworder.push_back(a);
    }
    int sol = search(1, n, t);
    fout << sol;
}