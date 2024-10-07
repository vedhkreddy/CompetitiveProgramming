#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int min_operations(string &s, int n) {
    if (n % 2 == 1) {
        return 1;  // If the length is odd, one deletion is necessary.
    }

    unordered_map<char, int> even_count, odd_count;
    
    // Counting frequencies of characters in even and odd indices
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            even_count[s[i]]++;
        } else {
            odd_count[s[i]]++;
        }
    }

    // Determine the most frequent characters
    vector<pair<int, char>> even_freq, odd_freq;
    for (auto &entry : even_count) {
        even_freq.push_back({entry.second, entry.first});
    }
    for (auto &entry : odd_count) {
        odd_freq.push_back({entry.second, entry.first});
    }

    sort(even_freq.rbegin(), even_freq.rend());
    sort(odd_freq.rbegin(), odd_freq.rend());

    int even_max_count = even_freq.empty() ? 0 : even_freq[0].first;
    int odd_max_count = odd_freq.empty() ? 0 : odd_freq[0].first;

    int even_max_char = even_freq.empty() ? 0 : even_freq[0].second;
    int odd_max_char = odd_freq.empty() ? 0 : odd_freq[0].second;

    int even_mismatches = n / 2 - even_max_count;
    int odd_mismatches = (n + 1) / 2 - odd_max_count;

    if (even_max_char != odd_max_char) {
        return even_mismatches + odd_mismatches;
    } else {
        int even_second_max = 0;
        int odd_second_max = 0;

        if (even_freq.size() > 1) {
            even_second_max = even_freq[1].first;
        }
        if (odd_freq.size() > 1) {
            odd_second_max = odd_freq[1].first;
        }

        int alternative_mismatches = min(
            even_mismatches + (n + 1) / 2 - odd_second_max,
            odd_mismatches + n / 2 - even_second_max
        );

        return min(even_mismatches + odd_mismatches, alternative_mismatches);
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;

        cin >> n >> s;
        cout << min_operations(s, n) << endl;
    }

    return 0;
}
