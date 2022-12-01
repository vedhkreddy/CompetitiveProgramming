#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> list;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        list.push_back(a);
    }
    for (int i = 0; i < n; i++){
        vector<int> v;
        vector<int> v1;
        for (int j = i; j < n-1; j++){
            string condition;
            if (list[i+1] - list[j] < 0){
                condition += "+ ";

            }
        }
        for (int j = i-1; j > -1; j--){

        }
    }
}