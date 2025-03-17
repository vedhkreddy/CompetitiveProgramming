#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int t;
    cin >> t;
    while (t--) {
        int arraySize, minimumSegments;
        ll threshold;
        cin >> arraySize >> minimumSegments >> threshold;

        vector<ll> array(arraySize);
        for (int i = 0; i < arraySize; i++) {
            cin >> array[i];
        }

        vector<ll> prefixSums(arraySize + 1, 0);
        for (int i = 0; i < arraySize; i++) {
            prefixSums[i + 1] = prefixSums[i] + array[i];
        }

        auto calculateRangeSum = [&](int startIndex, int endIndex) {
            return prefixSums[endIndex] - prefixSums[startIndex];
        };

        auto computePrefixSegments = [&]() -> vector<int> {
            vector<int> prefixSegments(arraySize + 1, 0);
            int segmentEnd = 0;
            ll currentSum = 0;

            for (int segmentStart = 0; segmentStart < arraySize; segmentStart++) {
                while (segmentEnd < arraySize && currentSum < threshold) {
                    currentSum += array[segmentEnd];
                    ++segmentEnd;
                    prefixSegments[segmentEnd] = max(prefixSegments[segmentEnd], prefixSegments[segmentEnd - 1]);
                }
                if (currentSum >= threshold) {
                    prefixSegments[segmentEnd] = max(prefixSegments[segmentEnd], 1 + prefixSegments[segmentStart]);
                }
                currentSum -= array[segmentStart];
            }

            for (int i = 1; i <= arraySize; i++) {
                prefixSegments[i] = max(prefixSegments[i], prefixSegments[i - 1]);
            }

            return prefixSegments;
        };

        auto prefixSegments = computePrefixSegments();
        reverse(array.begin(), array.end());
        auto suffixSegments = computePrefixSegments();
        reverse(array.begin(), array.end());
        reverse(suffixSegments.begin(), suffixSegments.end());

        if (prefixSegments[arraySize] < minimumSegments) {
            cout << -1 << endl;
            continue;
        }

        int segmentEnd = 0;
        ll maximumSum = 0;

        for (int segmentStart = 0; segmentStart < arraySize; segmentStart++) {
            while (segmentEnd < arraySize && 
                   prefixSegments[segmentStart] + suffixSegments[segmentEnd + 1] >= minimumSegments) {
                ++segmentEnd;
            }
            if (prefixSegments[segmentStart] + suffixSegments[segmentEnd] >= minimumSegments) {
                maximumSum = max(maximumSum, calculateRangeSum(segmentStart, segmentEnd));
            }
        }

        cout << maximumSum << endl;
    }
}
