#include<bits/stdc++.h>
 
using namespace std;
 
using ll = long long;
template<class T>
using pr = pair<T, T>;
 
vector<vector<int>> A, B;
vector<int> ans;
 
int n, m;
void rec(vector<int>& P, vector<int>& Q, int idx) {
    if (P.empty() || Q.empty()) return;
    for (auto u: P) ans[u] = max(ans[u], idx);
    if (idx == m) return;
    vector<vector<int>> S(m), T(m);
    for (auto u: P) S[A[u][idx]].push_back(u);
    for (auto u: Q) T[B[u][idx]].push_back(u);
    for (int i = 0; i < m; ++i) rec(S[i], T[i], idx + 1);
}
 
vector<int> get_inv(const vector<int>& P) {
    vector<int> Q(m);
    for (int i = 0; i < m; ++i) Q[P[i]] = i;
    return Q;
}
 
void pqr(){
    A.clear();
    B.clear();
    ans.clear();
    // int n, m;
    cin >> n >> m;
    ans.resize(n);
    A.resize(n, vector<int>(m));
    B.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> A[i][j];
            --A[i][j];
        }
        B[i] = get_inv(A[i]);
    }
    vector<int> X(n);
    iota(X.begin(), X.end(), 0);
    auto Y = X;
    rec(X, Y, 0);
    for (auto u: ans) cout << u << ' ';
    cout << '\n';
}
 
int main() {
    int testcases;
    testcases = 1;
    cin >> testcases;
    while(testcases--) {
        pqr();
    }
    return 0;
}