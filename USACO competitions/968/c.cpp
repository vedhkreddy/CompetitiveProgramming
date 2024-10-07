#include <bits/stdc++.h>
#define pb emplace_back
#define fst first
#define scd second
#define mkp make_pair
#define mems(a, x) memset((a), (x), sizeof(a))

using namespace std;
typedef long long ll;
typedef double db;
typedef unsigned long long ull;
typedef long double ldb;
typedef pair<int, int> pii;

const int maxStrLen = 1000100;

int strLen;
pii freqArray[99];
char inputStr[maxStrLen];

void solve() {
    scanf("%d%s", &strLen, inputStr + 1);
    for (int i = 0; i < 26; ++i) {
        freqArray[i] = mkp(0, i);
    }
    for (int i = 1; i <= strLen; ++i) {
        ++freqArray[inputStr[i] - 'a'].fst;
    }
    sort(freqArray, freqArray + 26, greater<pii>());
    queue<pii> charQueue;
    while (freqArray[0].fst > freqArray[1].fst) {
        putchar('a' + freqArray[0].scd);
        --freqArray[0].fst;
    }
    for (int i = 0; i < 26; ++i) {
        charQueue.push(freqArray[i]);
    }
    while (charQueue.size()) {
        pii currentChar = charQueue.front();
        charQueue.pop();
        if (!currentChar.fst) {
            continue;
        }
        putchar('a' + currentChar.scd);
        --currentChar.fst;
        charQueue.push(currentChar);
    }
    putchar('\n');
}

int main() {
    int testCases = 1;
    scanf("%d", &testCases);
    while (testCases--) {
        solve();
    }
    return 0;
}
