#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
#define forn(i, n) for (int i = 0; i < int(n); i++)
 
int main() {
    int t;
    cin >> t;
    forn(tt, t) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> p(n);
        forn(i, n)
            p[i] = i;
        if (tt > 0)
            cout << endl;
        forn(round, k) {
            int index = 0;
            forn(table, m) {
                int size = n / m;
                if (table < n % m)
                    size++;
                cout << size;
                forn(j, size)
                    cout << " " << p[index++] + 1;
                cout << endl;                        
            }
            rotate(p.begin(), p.begin() + (n % m) * ((n + m - 1) / m), p.end());
        }
    }