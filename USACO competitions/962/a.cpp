#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n; 
        int minAnimals = n / 4 + (n % 4 != 0);

        cout << minAnimals << endl;
    }
    return 0;
}
