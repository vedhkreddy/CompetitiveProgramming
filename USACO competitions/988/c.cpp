#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        if (n < 5){
            cout << -1 << endl;
            continue;
        }
        deque<int> res;
        res.push_back(5);
        res.push_back(4);
        for (int i = 1; i <= n; i++){
            if (i != 5 && i != 4){
                if (i % 2 == 0){
                    res.push_back(i);
                }
                else{
                    res.push_front(i);
                }
            }
        }
        deque<int>::iterator it;
        for (it = res.begin(); it != res.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
}