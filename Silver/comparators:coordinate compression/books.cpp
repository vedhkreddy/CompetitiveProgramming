#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

int main(){
    //ifstream cin("books.in");
    int n, t;
    cin >> n >> t;
    int arr[n];
    int startpoint = -1;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] <= t && startpoint == -1){
            startpoint = i;
        }
    }
    if (startpoint == -1){
        cout << 0;
        return 0;
    }
    int p1 = startpoint; int p2 = startpoint;
    int time = arr[startpoint];
    int max = 1;
    int cur = 1;
    bool starting = true;
    while (p1 != n-1){
        if (time + arr[p2+1] > t){
            if (p1 == p2){
                p1++;
                p2 = p1;
                time = arr[p1];
                cur = 1;
            }
            p1++;
            time -= arr[p1-1];
            cur--;
        }
        else{
            p2++;
            time += arr[p2];
            cur++;
        }
        if (cur > max){
            max = cur;
        }
        if (p2 == n-1){
            break;
        }
    }
    cout << max;
}