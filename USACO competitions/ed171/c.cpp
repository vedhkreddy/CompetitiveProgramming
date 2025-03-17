#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX_SIZE = 400043;
char inputBuffer[MAX_SIZE];

bool isPossible(const string& binaryString, int target)
{
    int length = binaryString.size();
    vector<int> usedPositions(length, 0);
    
    for (int i = length - 1; i >= 0; i--) {
        if (target > 0 && binaryString[i] == '1') {
            usedPositions[i] = 1;
            target--;
        }
    }

    int balance = 0;
    for (int i = 0; i < length; i++) {
        if (usedPositions[i]) {
            balance--;
            if (balance < 0) return false;
        } else {
            balance++;
        }
    }
    return true;
}

void processTestCase()
{
    int length;
    cin >> length;
    cin >> inputBuffer;
    
    if (length == 1) {
        cout << "1\n";
        return;
    }

    string binaryString = inputBuffer;
    int onesCount = count(binaryString.begin(), binaryString.end(), '1');
    
    int left = 1;
    int right = onesCount + 1;

    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (isPossible(binaryString, mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    long long result = 0;
    for (int i = length - 1; i >= 0; i--) {
        if (binaryString[i] == '1' && left > 0) {
            left--;
        } else {
            result += (i + 1);
        }
    }
    cout << result << '\n';
}

int main()
{
    int testCases;
    cin >> testCases;
    for (int i = 0; i < testCases; i++) {
        processTestCase();
    }
}
