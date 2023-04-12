#include <iostream>
#include <fstream>
using namespace std;

using namespace std;

void test_case() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
        } else {
            ++y;
        }
    }
    int add_x = n - 1 - x, add_y = n - 1 - y;
    long long bad = 0;
    x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
            for (int j = 0; j < add_x; ++j) {
                ++x;
            }
            add_x = 0;
        } else {
            bad += n - x - 1;
            ++y;
        }
    }
    bad += n - x - 1;
    x = 0, y = 0;
    for (auto &i : s) {
        if (i == 'D') {
            ++x;
        } else {
            bad += x;
            ++y;
            for (int j = 0; j < add_y; ++j) {
                bad += x;
                ++y;
            }
            add_y = 0;
        }
    }
    bool same = true;
    for (auto &i : s) {
        if (i != s[0]) {
            same = false;
            break;
        }
    }
    if (same) {
        cout << n << "\n";
    } else {
        cout << (long long) n * n - bad << "\n";
    }
}

int main() {
    int test_case_number = 1;
    cin >> test_case_number;
    while (test_case_number--) {
        test_case();
    }
}