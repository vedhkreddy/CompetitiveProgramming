#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;
    
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    set < int > s;
    for (int i = 0; i < n; ++i) {
        s.insert(i);
    }
    
    int b[n];
    vector < int > sizen(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i]; --b[i];
        if (b[i] == -2) continue;
        ++sizen[b[i]];
        if (sizen[b[i]] == 1) {
            s.erase(b[i]);
        }
    }
    
    long long sum = 0;
    vector < int > res[2];
    
    while (!s.empty()) {
        int v = *s.begin();
        s.erase(s.begin());
        int w = b[v];
        sum += a[v];
        if (a[v] >= 0) {
            if (w >= 0) {
                a[w] += a[v];
            }
            res[0].push_back(v);
        } else {
            res[1].push_back(v);
        }
        if (w >= 0) {
            --sizen[w];
            if (sizen[w] == 0) {
                s.insert(w);
            }
        }
    }
    
    cout << sum << endl;
    for (int to : res[0]) cout << to + 1 << ' ';
    
    reverse(res[1].begin(), res[1].end());
    
    for (int to : res[1]) cout << to + 1 << ' ';
    cout << endl;
}