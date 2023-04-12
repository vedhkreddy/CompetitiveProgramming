#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int main(){
    for (int i = 0 ; i < 100; i++){
        for (int j = i; j < 100; j++){
            for (int k = j; k < 100; k++){
                for (int l = k; l < 100; l++){
                set<int> s;
                s.insert(i); s.insert(j); s.insert(k); s.insert(l);
                if (size(s) < 4){
                    continue;
                }
                if (l - i == sqrt(j + i + k + l)){
                    cout << i << " " << j << " " << k << " " << l << endl;
                }
                }
            }

        }
    }
}