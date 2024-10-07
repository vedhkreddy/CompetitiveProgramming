#include <iostream>
using namespace std;

int main() {
    int t;  
    cin >> t;
    
    while (t--) {
        int n;  
        cin >> n;
        
        char beatmap[n][4];  
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 4; j++) {
                cin >> beatmap[i][j];
            }
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < 4; j++) {
                if (beatmap[i][j] == '#') {
                    cout << j + 1 << " ";  
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}
