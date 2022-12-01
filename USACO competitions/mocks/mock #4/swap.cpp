#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int order[100002];
bool visited[100002];


int main(){
    int n, m, k;
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    fin >> n >> m >> k;

    for (int i = 1; i <= n; i++){
        order[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int l,r;
        fin >> l >> r;
        for (int j = 0; j < (r-l+1)/2; j++) {
            int temp = order[l+j];
            order[l+j] = order[r-j];
            order[r-j] = temp;
        }
    }

    for (int i = 1; i <= n; i++){
        if (!visited[i]){
            vector<int> cycle;
            cycle.push_back(i);
            int start = order[i];
            visited[i] = true;
            while(start != i){
                visited[start] = true;
                cycle.push_back(start);
                start = order[start];
            }
            
            int mod = k % cycle.size();
            for (int j = 0; j < cycle.size(); j++) {
                order[cycle[j]] = cycle[(j+mod) % cycle.size()];
            }
            cycle.clear();
        }
    }

    for (int i = 1 ; i <= n; i++){
        fout << order[i] << endl;
    }
}
