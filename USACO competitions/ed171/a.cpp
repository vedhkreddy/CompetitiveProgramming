#include <iostream>
#include <algorithm>
using namespace std;

void printCoordinates(int X, int Y) {
    int M = min(X, Y);
    cout << "0 0 " << M << " " << M << endl;
    cout << "0 " << M << " " << M << " 0" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int X, Y, K;
        cin >> X >> Y >> K;
        printCoordinates(X, Y);
    }
    return 0;
}
