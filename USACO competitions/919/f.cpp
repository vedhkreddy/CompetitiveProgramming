#include <iostream>
using namespace std;

int query(int l, int r) {
    cout << "? " << l << " " << r << endl;
    cout.flush();  // flush the output buffer to ensure the query is sent
    int sum;
    cin >> sum;
    if (sum == -1) exit(0);  // handle error case if the interactor returns -1
    return sum;
}

void find_kth_zero(int n, int k) {
    int l = 1, r = n;  // Set the boundaries of the array (1-indexed)
    while (l < r) {
        int mid = (l + r) / 2;
        int ones_in_left_half = query(l, mid);  // Query the number of 1's in the left half
        int zeros_in_left_half = (mid - l + 1) - ones_in_left_half;  // Calculate the number of 0's

        if (zeros_in_left_half >= k) {
            r = mid;  // The k-th zero is in the left half
        } else {
            l = mid + 1;  // The k-th zero is in the right half
            k -= zeros_in_left_half;  // Update k to look for the (k - zeros_in_left_half)-th zero
        }
    }
    cout << "! " << l << endl;
    cout.flush();  // Flush after the final answer
}

int main() {
    int n, t;
    cin >> n >> t;
    
    while (t--) {
        int k;
        cin >> k;
        find_kth_zero(n, k);
    }

    return 0;
}
