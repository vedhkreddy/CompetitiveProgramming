#include <bits/stdc++.h>
using namespace std;

struct MinimizeX {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first > b.first;
    }
};

struct MaximizeX {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

struct MinimizeY {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

struct MaximizeY {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    }
};

void solve() {
    int a, b, n, m;
    cin >> a >> b >> n >> m;

    priority_queue<pair<int, int>, vector<pair<int, int>>, MinimizeX> pqMinX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaximizeX> pqMaxX;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MinimizeY> pqMinY;
    priority_queue<pair<int, int>, vector<pair<int, int>>, MaximizeY> pqMaxY;
    map<pair<int, int>, bool> done;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        pqMaxX.push(make_pair(x, y));
        pqMinX.push(make_pair(x, y));
        pqMaxY.push(make_pair(x, y));
        pqMinY.push(make_pair(x, y));
        done[make_pair(x, y)] = false;
    }

    int leftBoundary = 1, rightBoundary = b;
    int topBoundary = 1, bottomBoundary = a;
    bool aliceTurn = true;
    int aliceres = 0, bobres = 0;

    for (int i = 0; i < m; i++) {
        char c;
        int k;
        cin >> c >> k;

        if (c == 'U') {
            while (!pqMinX.empty() && pqMinX.top().first < topBoundary + k) {
                auto chip = pqMinX.top();
                pqMinX.pop();
                if (!done[chip] && chip.second >= leftBoundary && chip.second <= rightBoundary) {
                    done[chip] = true;
                    if (aliceTurn) aliceres++;
                    else bobres++;
                }
            }
            topBoundary += k;
        } else if (c == 'D') {
            while (!pqMaxX.empty() && pqMaxX.top().first > bottomBoundary - k) {
                auto chip = pqMaxX.top();
                pqMaxX.pop();
                if (!done[chip] && chip.second >= leftBoundary && chip.second <= rightBoundary) {
                    done[chip] = true;
                    if (aliceTurn) aliceres++;
                    else bobres++;
                }
            }
            bottomBoundary -= k;
        } else if (c == 'L') {
            while (!pqMinY.empty() && pqMinY.top().second < leftBoundary + k) {
                auto chip = pqMinY.top();
                pqMinY.pop();
                if (!done[chip] && chip.first >= topBoundary && chip.first <= bottomBoundary) {
                    done[chip] = true;
                    if (aliceTurn) aliceres++;
                    else bobres++;
                }
            }
            leftBoundary += k;
        } else if (c == 'R') {
            while (!pqMaxY.empty() && pqMaxY.top().second > rightBoundary - k) {
                auto chip = pqMaxY.top();
                pqMaxY.pop();
                if (!done[chip] && chip.first >= topBoundary && chip.first <= bottomBoundary) {
                    done[chip] = true;
                    if (aliceTurn) aliceres++;
                    else bobres++;
                }
            }
            rightBoundary -= k;
        }

        aliceTurn = !aliceTurn; // Switch turns
    }

    cout << aliceres << " " << bobres << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}