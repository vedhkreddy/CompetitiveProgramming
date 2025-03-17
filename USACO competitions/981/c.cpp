#include <iostream>
#include <vector>
using namespace std;

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int size;
        cin >> size;
        vector<int> arr(size + 1);
        for (int i = 1; i <= size; ++i) {
            cin >> arr[i];
        }

        for (int i = size / 2 - 1; i >= 1; --i) {
            if (arr[i] == arr[i + 1] || arr[size - i + 1] == arr[size - i]) {
                swap(arr[i], arr[size - i + 1]);
            }
        }

        int repeatCount = 0;
        for (int i = 1; i < size; ++i) {
            if (arr[i] == arr[i + 1]) {
                repeatCount++;
            }
        }
        
        cout << repeatCount << endl;
    }
}
