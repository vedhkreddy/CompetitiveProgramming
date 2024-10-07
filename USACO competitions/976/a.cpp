#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int operations = 0;
        
        if (k == 1) {
            operations = n;
        } else {
            while (n > 0) {
                operations += n % k;
                n /= k;
            }
        }
        
        cout << operations << "\n";
    }
    return 0;
}
