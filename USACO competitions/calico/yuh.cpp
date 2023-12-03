#include <iostream>
#include <vector>
using namespace std;

int solve(int N, int M, int K, vector<int>& S, vector<int>& E) {
    vector<vector<int>> stationStarts(M);
    vector<vector<int>> stationEnds(M);
    vector<int> onTrain;
    int stationId = 0;
    int miles = 0;
    int passengersTotal = 0;

    for (int i = 0; i < M; i++) {
        stationStarts[i] = vector<int>();
        stationEnds[i] = vector<int>();
    }

    for (int i = 0; i < N; i++) {
        stationStarts[S[i] - 1].push_back(i);
        stationEnds[E[i] - 1].push_back(i);
    }

    while (passengersTotal < N) {
        for (int i = 0; i < stationEnds[stationId].size(); i++) {
            if (find(onTrain.begin(), onTrain.end(), stationEnds[stationId][i]) != onTrain.end()) {
                passengersTotal++;
            }
        }

        for (auto it = onTrain.begin(); it != onTrain.end();) {
            if (find(stationEnds[stationId].begin(), stationEnds[stationId].end(), *it) != stationEnds[stationId].end()) {
                it = onTrain.erase(it);
            } else {
                ++it;
            }
        }

        if (passengersTotal == N) {
            break;
        }

        for (int i = 0; i < stationStarts[stationId].size(); i++) {
            if (onTrain.size() == K) {
                break;
            }
            onTrain.push_back(stationStarts[stationId][i]);
        }

        for (auto it = stationStarts[stationId].begin(); it != stationStarts[stationId].end();) {
            if (find(onTrain.begin(), onTrain.end(), *it) != onTrain.end()) {
                it = stationStarts[stationId].erase(it);
            } else {
                ++it;
            }
        }

        stationId++;
        if (stationId == M) {
            stationId = 0;
        }
        miles++;
    }

    return miles;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M, K;
        cin >> N >> M >> K;
        vector<int> S(N);
        vector<int> E(N);

        for (int j = 0; j < N; j++) {
            cin >> S[j];
        }

        for (int j = 0; j < N; j++) {
            cin >> E[j];
        }

        cout << solve(N, M, K, S, E) << endl;
    }

    return 0;
}