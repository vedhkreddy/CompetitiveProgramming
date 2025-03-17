#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> notes(n);
        for (int i = 0; i < n; ++i) {
            cin >> notes[i];
        }
        bool perfect = true;
        for (int i = 0; i < n - 1; ++i) {
            int interval = abs(notes[i] - notes[i + 1]);
            if (interval != 5 && interval != 7) {
                perfect = false;
                break;
            }
        }
        if (perfect == true){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
