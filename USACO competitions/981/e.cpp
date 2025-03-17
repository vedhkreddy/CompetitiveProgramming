#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int numElements;
        cin >> numElements;
        
        int permutation[numElements + 1];
        for (int i = 1; i <= numElements; i++) {
            cin >> permutation[i];
        }
        
        bool visited[numElements + 1];
        memset(visited, false, sizeof(visited));
        
        int swapsRequired = 0;
        for (int i = 1; i <= numElements; i++) {
            if (!visited[i]) {
                int currentPosition = i;
                int cycleLength = 0;
                
                while (!visited[currentPosition]) {
                    cycleLength++;
                    visited[currentPosition] = true;
                    currentPosition = permutation[currentPosition];
                }
                
                swapsRequired += (cycleLength - 1) / 2;
            }
        }
        
        cout << swapsRequired << '\n';
    }
    
    return 0;
}
