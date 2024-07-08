#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> degree(N, 0);

    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        degree[a - 1]++;
        degree[b - 1]++;
    }

    int maxDegree = 0;
    for (int i = 0; i < N; ++i) {
        if (degree[i] > maxDegree) {
            maxDegree = degree[i];
        }
    }

    cout << maxDegree + 1 << '\n';

    return 0;
}
