#include <iostream>
#include <cmath>
using namespace std;

bool isPerfectSquare(int n) {
    int sq = sqrt(n);
    return (sq * sq == n);
}

bool isBeautifulSquareMatrix(const string &s, int n) {
    int size = sqrt(n);

    // Check first row
    for (int i = 0; i < size; i++) {
        if (s[i] != '1') return false;
    }

    // Check last row
    for (int i = n - size; i < n; i++) {
        if (s[i] != '1') return false;
    }

    // Check middle rows
    for (int i = 1; i < size - 1; i++) {
        if (s[i * size] != '1' || s[(i + 1) * size - 1] != '1') return false;
        for (int j = 1; j < size - 1; j++) {
            if (s[i * size + j] != '0') return false;
        }
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (!isPerfectSquare(n)) {
            cout << "No" << endl;
        } else if (isBeautifulSquareMatrix(s, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
