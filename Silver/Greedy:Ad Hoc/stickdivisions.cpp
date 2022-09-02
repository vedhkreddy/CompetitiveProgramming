#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int x, n;
    cin >> x >> n;
    priority_queue<int> mypq;
    for (int i = 0; i < n; i++){
        int a;
        cin >> a;
        mypq.push(-1 * a);
    }
    int cost = 0;
    while (mypq.size() > 1){
        int a = mypq.top();
        mypq.pop();
        int b = mypq.top();
        mypq.pop();
        cost += (-1*(a+b));
        mypq.push(a+b);
    }
    cout << cost << endl;
}