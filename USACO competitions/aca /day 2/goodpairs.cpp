#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        int k;
        cin >> k;
        vector<int> v;
        for (int i = 0; i < k; i++){
            int a;
            cin >> a;
            v.push_back(a);
        }
        int min = 1000000000; int max = 0;
        int minpos; int maxpos;
        for (int j = 0; j < v.size(); j++){
            if (v[j] > max){
                max = v[j];
                maxpos = j+1;
            }
            if (v[j] < min){
                min = v[j];
                minpos = j+1;
            }
        }
        cout << minpos << " " << maxpos << endl;
    }
}