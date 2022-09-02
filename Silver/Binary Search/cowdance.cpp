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
    int sum = 0;
    for(int i = 0; i < k; i++){
        pq.push(coworder[i]);
        if (coworder[i] > max){
            max = coworder[i];
        }
        sum += coworder[i];
    }
    if (k == n){
        return max;
    }
    if (k == 1){
        return sum;
    }
    int cur;
    while(curindex != n-1){
        curindex++;
        int out = pq.top();
        pq.pop();
        pq.push(coworder[curindex] + out);
        cur = coworder[curindex] + out;
    }
    return cur;
}

int search(int lo, int n, int t){
    int hi = n;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (isgood(mid, n) <= t){
            if (mid == 1){
                return mid;
            }
            if (isgood(mid-1, n) > t){
                return mid;
            }
            else{
                hi = mid;
            }
        }
        else{
            lo = mid;
        }
    }
    return 0; 
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