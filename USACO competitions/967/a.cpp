#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int size;
        cin >> size;

        vector<int> arr(size);
        for (int i = 0; i < size; ++i) {
            cin >> arr[i];
        }

        vector<int> frequency(size + 1, 0);
        for (int num : arr) {
            frequency[num]++;
        }

        int max_freq = *max_element(frequency.begin(), frequency.end());
        cout << size - max_freq << '\n';
    }

    return 0;
}
