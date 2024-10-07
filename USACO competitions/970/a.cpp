#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        // Condition 1: The total sum must be even
        if ((a + 2 * b) % 2 != 0) {
            cout << "NO" << endl;
        } 
        // Condition 2: If b is odd, we need at least 2 ones to balance
        else if (b % 2 == 1 && a < 2) {
            cout << "NO" << endl;
        } 
        else {
            cout << "YES" << endl;
        }
    }
    
    return 0;
}
