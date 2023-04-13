#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    getline(cin, str);
    long long answer = 0;
    long long waiting[7] = {0};
    long long rem = str.length();
    for (char letter : str) {
        waiting[0]++;
        for (int d = 5; d >= 0; d--) {
            if (letter == "bessie"[d]) {
                waiting[d + 1] += waiting[d];
                waiting[d] = 0;
            }
        }
        answer += waiting[6] * rem;
        waiting[0] += waiting[6];
        waiting[6] = 0;
        rem--;
    }
    cout << answer << endl;
    return 0;
}