#include <iostream>
using namespace std;

long long arr[1000000];
int main (){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    long long cur = 0; long long max = -2000000000;
    for (int i = 1; i <= n; i++){
        cur += arr[i];
        if (cur > max){
            max = cur;
        }
        if (cur < 0){
            cur = 0;
        }
    }
    cout << max;
}