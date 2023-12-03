#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n, k;
    cin >> n >> k;
    
    int a[100] = {0};
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
 
    int card_num = n / k;
    int q;
    cin >> q;
 
    map<vector<int>, int> M;
    int used[100] = {0};
    int mmax = -9999999;
    int mmin = 9999999;
    int remain = k;
 
    for (int i = 0; i < q; i++) {
        vector<int> V;
        for (int j = 0; j < card_num; j++) {
            int tmp;
            cin >> tmp;
            V.push_back(tmp - 1);
        }
        sort(V.begin(), V.end());
 
        if (M.find(V) == M.end()) {
            M[V] = 1;
            int sum = 0;
            for (int j = 0; j < card_num; j++) {
                sum += a[V[j]];
                used[V[j]] = 1;
            }
            if (sum > mmax) mmax = sum;
            if (sum < mmin) mmin = sum;
            remain--;
        }
    }
 
    vector<int> rcards;
    for (int i = 0; i < n; i++) {
        if (!used[i]) rcards.push_back(a[i]);
    }
    sort(rcards.begin(), rcards.end());
 
    if (remain) {
        int sum = 0;
        for (int j = 0; j < card_num; j++) {
            sum += rcards[j];
        }
        if (sum < mmin) mmin = sum;
 
        sort(rcards.rbegin(), rcards.rend());
        sum = 0;
        for (int j = 0; j < card_num; j++) {
            sum += rcards[j];
        }
        if (sum > mmax) mmax = sum;
    }
 
    cout << fixed << setprecision(9) << mmin / static_cast<double>(card_num) << " " << mmax / static_cast<double>(card_num) << endl;
 
    return 0;
}