#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
using namespace std;

const int MAX_N = 1002;

int N, R;
char grid[MAX_N][MAX_N]; // pad with .'s
int region[MAX_N][MAX_N], area[MAX_N*MAX_N], perimeter[MAX_N*MAX_N];

typedef pair<int,int> pii;

void visit(int i, int j, int r) {
    stack<pii> to_visit;
    to_visit.push(make_pair(i, j));

    while (!to_visit.empty()) {
        pii current = to_visit.top();
        to_visit.pop();
        i = current.first; j = current.second;

        if (region[i][j] != 0 || grid[i][j] == '.') continue;

        region[i][j] = r;
        area[r]++;

        to_visit.push(make_pair(i-1, j));
        to_visit.push(make_pair(i+1, j));
        to_visit.push(make_pair(i, j-1));
        to_visit.push(make_pair(i, j+1));
    }
}

void find_perimeters() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int r = region[i][j];
            if (r == 0) continue;

            if (region[i-1][j] == 0) perimeter[r]++;
            if (region[i+1][j] == 0) perimeter[r]++;
            if (region[i][j-1] == 0) perimeter[r]++;
            if (region[i][j+1] == 0) perimeter[r]++;
        }
    }
}

int main() {
    ifstream fin("perimeter.in");
    ofstream fout("perimeter.out");

    fin >> N;
    string s;

    // Initialize grid with padding
    for (int i = 0; i < N+2; i++) {
        grid[0][i] = grid[N+1][i] = '.';
    }

    // Read input grid
    for (int i = 1; i <= N; i++) {
        grid[i][0] = grid[i][N+1] = '.';
        fin >> s;
        for (int j = 1; j <= N; j++) {
            grid[i][j] = s[j-1];
        }
    }

    // Find regions and calculate areas
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (grid[i][j] == '#' && region[i][j] == 0) {
                visit(i, j, ++R);
            }
        }
    }

    // Calculate perimeters of regions
    find_perimeters();

    // Find the region with the maximum area and minimum perimeter
    int best_a = 0, best_p = 0;
    for (int i = 1; i <= R; i++) {
        if (area[i] > best_a || (area[i] == best_a && perimeter[i] < best_p)) {
            best_a = area[i];
            best_p = perimeter[i];
        }
    }

    fout << best_a << " " << best_p << "\n";

    return 0;
}
