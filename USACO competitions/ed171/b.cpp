#include <bits/stdc++.h>

using namespace std;

int main() {
  int testCases;
  cin >> testCases;
  while (testCases--) {
    int arrSize;
    cin >> arrSize;
    vector<long long> elements(arrSize);
    for (auto& elem : elements) cin >> elem;

    long long minDiff = LLONG_MAX;

    auto calculateDifference = [&](vector<long long> arr) {
      sort(arr.begin(), arr.end());
      for (int i = 1; i < (int)arr.size(); ++i)
        if (arr[i - 1] == arr[i]) return;
      long long maxDifference = 0;
      for (int i = 0; i < (int)arr.size(); i += 2)
        maxDifference = max(maxDifference, arr[i + 1] - arr[i]);
      minDiff = min(minDiff, maxDifference);
    };

    if (arrSize % 2 == 0) {
      calculateDifference(elements);
      cout << minDiff << '\n';
      continue;
    }

    for (int i = 0; i < arrSize; ++i) {
      for (int offset : {-1, 1}) {
        elements.push_back(elements[i] + offset);
        calculateDifference(elements);
        elements.pop_back();
      }
    }

    cout << minDiff << '\n';
  }
}
