#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> left_max(n), right_max(n);

        stack<int> left_stack;
        for (int i = 0; i < n; ++i) {
            while (!left_stack.empty() && a[left_stack.top()] <= a[i]) {
                left_stack.pop();
            }
            left_max[i] = left_stack.empty() ? a[i] : max(a[i], left_max[left_stack.top()]);
            left_stack.push(i);
        }

        stack<int> right_stack;
        for (int i = n - 1; i >= 0; --i) {
            while (!right_stack.empty() && a[right_stack.top()] >= a[i]) {
                right_stack.pop();
            }
            right_max[i] = right_stack.empty() ? a[i] : max(a[i], right_max[right_stack.top()]);
            right_stack.push(i);
        }

        for (int i = 0; i < n; ++i) {
            cout << max(left_max[i], right_max[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}
