#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main(){
    int N, L;
    cin >> N >> L;
    int citations[N];
    for (int i = 0; i < N; i++){
        cin >> citations[i];
    }
    sort(citations, citations+N, greater<int>());
    int almostcount = 0;
    int initialh = 0;
    bool all = true;
    for (int i = 1; i <= N; i++){
        if (citations[i - 1] >= i){
            initialh++;
            if (citations[i - 1] != citations[0]){
                all = false;
            }
        }
        else{
            all = false;
            break;
        }
    }
    for(int i = 1; i <= N; i++){
        if (citations[i - 1] - i == -1){
            almostcount++;
        }
    }
    if (all == true && citations[0] == L){
        cout << initialh + 1;
        return 0;
    }
    if (almostcount > L){
        cout << initialh + L;
    }
    else{
        cout << initialh + almostcount;
    }
}