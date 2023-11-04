#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
using namespace std;

#define MAX_N 100000
#define INF 1000000000

int numElements, distanceValue;
int coordinatesA[2 * MAX_N];
int coordinatesB[2 * MAX_N];
int distances[2 * MAX_N];

struct CompareA {
    bool operator()(int a, int b) const {
        return coordinatesB[a] < coordinatesB[b];
    }
};

struct CompareB {
    bool operator()(int a, int b) const {
        return coordinatesA[a] < coordinatesA[b];
    }
};

multiset<int, CompareA> setA;
multiset<int, CompareB> setB;

int queueArr[2 * MAX_N];
int currentIdx, length;

int main() {
    ifstream cin("piepie.in");
    ofstream cout("piepie.out");
    cin >> numElements >> distanceValue;
    for (int i = 0; i < 2 * numElements; i++) {
        cin >> coordinatesA[i] >> coordinatesB[i];
        coordinatesA[i] = -coordinatesA[i];
        coordinatesB[i] = -coordinatesB[i];
        distances[i] = -1;
    }
    for (int i = 0; i < numElements; i++) {
        if (coordinatesB[i] == 0)
            queueArr[length++] = i, distances[i] = 1;
        else
            setA.insert(i);
        if (coordinatesA[numElements + i] == 0)
            queueArr[length++] = numElements + i, distances[numElements + i] = 1;
        else
            setB.insert(numElements + i);
    }

    multiset<int, CompareA>::iterator iterA;
    multiset<int, CompareB>::iterator iterB;

    while (currentIdx < length) {
        int index = queueArr[currentIdx];
        if (index < numElements) {
            while (true) {
                iterB = setB.lower_bound(index);
                if (iterB == setB.end() || coordinatesA[*iterB] > coordinatesA[index] + distanceValue)
                    break;
                distances[*iterB] = distances[index] + 1;
                queueArr[length++] = *iterB;
                setB.erase(iterB);
            }
        } else {
            while (true) {
                iterA = setA.lower_bound(index);
                if (iterA == setA.end() || coordinatesB[*iterA] > coordinatesB[index] + distanceValue)
                    break;
                distances[*iterA] = distances[index] + 1;
                queueArr[length++] = *iterA;
                setA.erase(iterA);
            }
        }
        currentIdx++;
    }

    for (int i = 0; i < numElements; i++)
        cout << distances[i] << '\n';
}