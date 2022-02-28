#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {0, 2, 0, 3, 0, 1, 0};
    for (int i : v){
        cout << i << endl;
    }
}