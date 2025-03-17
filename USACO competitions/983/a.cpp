#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> switches(2 * n);
        int cnt1 = 0, cnt0 = 0;

        for (int i = 0; i < 2 * n; i++) {
            cin >> switches[i];
            if (switches[i] == 1)
                cnt1++;
            else
                cnt0++;
        }

        // Maximum lights on is min(cnt0, cnt1)
        int max_lights_on = min(cnt0, cnt1);
        
        // Minimum lights on is cnt0 % 2
        int min_lights_on = cnt0 % 2;

        cout << min_lights_on << " " << max_lights_on << endl;
    }

    return 0;
}
