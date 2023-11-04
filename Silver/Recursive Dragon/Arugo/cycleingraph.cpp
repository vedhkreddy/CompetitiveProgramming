#include <bits/stdc++.h>
using namespace std;
#define MAX_NODES 100010

int nodeCount[MAX_NODES], nodes, edges, depth;
vector<int> edgesList[MAX_NODES];
int vis[MAX_NODES];

int main() {
    cin >> nodes >> edges >> depth;

    for (int i = 0; i < edges; i++) {
        int nodeA, nodeB;
        cin >> nodeA >> nodeB;
        edgesList[nodeA].push_back(nodeB);
        edgesList[nodeB].push_back(nodeA);
    }

    int top = 1;
    vis[top] = 1;

    while (true) {
        int current = vis[top];
        nodeCount[current] = top;

        int minDepth = nodes + 1, minPosition = -1;
        for (unsigned i = 0; i < edgesList[current].size(); i++) {
            int nextNode = edgesList[current][i];
            if (nodeCount[nextNode] < minDepth) {
                minDepth = nodeCount[nextNode];
                minPosition = nextNode;
            }
        }

        if (minDepth == 0) {
            vis[top + 1] = minPosition;
        } else {
            cout << top - minDepth + 1 << endl;
            for (int i = minDepth; i <= top; i++)
                cout << vis[i] << (i == top ? '\n' : ' ');
            return 0;
        }

        top++;
    }
}