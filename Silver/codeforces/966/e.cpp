#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Cell {
    int x, y, coverage;
};

bool compareCoverage(const Cell &a, const Cell &b) {
    return a.coverage > b.coverage;
}

bool compareHeight(int a, int b) {
    return a > b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        
        int w;
        cin >> w;
        
        vector<int> heights(w);
        for (int i = 0; i < w; i++) {
            cin >> heights[i];
        }
        
        vector<Cell> cells;
        
        // Calculate coverage for each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int coverage = (min(i, n - k) - max(-1, i - k)) * (min(j, m - k) - max(-1, j - k));
                cells.push_back({i, j, coverage});
            }
        }
        
        // Sort cells based on coverage
        sort(cells.begin(), cells.end(), compareCoverage);
        
        // Sort heights in descending order
        sort(heights.begin(), heights.end(), compareHeight);
        
        long long maxSpectacle = 0;
        
        // Place the tallest gorillas in cells with the highest coverage
        for (int i = 0; i < w; i++) {
            maxSpectacle += (long long)heights[i] * cells[i].coverage;
        }
        
        cout << maxSpectacle << '\n';
    }
    
    return 0;
}
