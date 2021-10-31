#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //ifstream cin("evenodd.in");
    int N;
    cin >> N;
    vector<int> cows;
    for (int i = 0; i < N; i++){
        int a;
        cin >> a;
        cows.push_back(a);
    }
    int count = 0;
    int cur = 0;
    while (cows.size() != 0){
        if (cur == 0){
            int index = -1;
            for (int i = 0; i < cows.size(); i++){
                if (cows[i] % 2 == 0){
                    index = i;
                    break;
                }
            }
            if (index == -1){
                if (cows.size() >= 2){
                    cows.erase(cows.begin());
                    cows.erase(cows.begin());
                    count++;
                }
                else{
                    count--;
                    break;
                }
            }
            else{
                cows.erase(cows.begin() + index);
                count++;
            }
        }
        else{
            int index = -1;
            for (int i = 0; i < cows.size(); i++){
                if (cows[i] % 2 == 1){
                    index = i;
                }
            }
            if (index == -1){
                break;
            }
            else{
                cows.erase(cows.begin() + index);
                count++;
            }
        }
        if (cur == 0){
            cur = 1;
        }
        else{
            cur = 0;
        }
    }
    cout << count;
}