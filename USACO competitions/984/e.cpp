#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ll rows, cols, queries;
    cin >> rows >> cols >> queries;

    vector<vector<ll>> matrix(rows, vector<ll>(cols));

    for (ll i = 0; i < rows; i++) {
        for (ll j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    for (ll i = 1; i < rows; i++) {
        for (ll j = 0; j < cols; j++) {
            matrix[i][j] |= matrix[i - 1][j];
        }
    }

    while (queries--) {
        ll conditions;
        cin >> conditions;

        ll left_bound = 0, right_bound = rows - 1;

        while (conditions--) {
            ll column, value;
            char operation;
            cin >> column >> operation >> value;
            column--;

            if (operation == '<') {
                ll low = -1, high = rows, mid;
                while (low + 1 != high) {
                    mid = (low + high) / 2;
                    if (matrix[mid][column] < value) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                if (low < right_bound) {
                    right_bound = low;
                }
            } else {
                ll low = -1, high = rows, mid;
                while (low + 1 != high) {
                    mid = (low + high) / 2;
                    if (matrix[mid][column] <= value) {
                        low = mid;
                    } else {
                        high = mid;
                    }
                }
                if (high > left_bound) {
                    left_bound = high;
                }
            }
        }

        if (left_bound <= right_bound) {
            cout << left_bound + 1 << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
