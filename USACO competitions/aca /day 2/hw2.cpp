#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int count = 0;
    for (int i = 0; i < 6; i++){
        int a; cin >> a; v.push_back(a);
        count += a;
    }

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            for (int k = 0; k < 6; k++){
                if (i == j || j == k || k == i){
                    continue;
                }
                if ((v[i] + v[j] + v[k])*2 == count){
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
}