#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int steps = 0;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        steps += a[i];
    }
    for (int i = 0, pos = 0; i < steps; i++) {
        if (pos == 0) {
            cout << 'R';
            pos++;
            a[pos]--;
        } else if (pos == n) {
            cout << 'L';
            a[pos]--;
            pos--;
        } else if (a[pos + 1] >= a[pos]) {
            cout << 'R';
            pos++;
            a[pos]--;
        } else {
            cout << 'L';
            a[pos]--;
            pos--;
        }
    }
    cout << endl;
}