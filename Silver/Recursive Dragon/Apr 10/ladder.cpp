#include <bits/stdc++.h>
using namespace std;

int main(){
    //ifstream cin("test.in");
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        v.push_back(a);
    }
    //generate
    int up[n];
    int down[n];

    int len = 0;
    int startpos = 0;
    for (int i = 0; i < n; i++){
        len++;
        if (i == n-1 || v[i] > v[i+1]){
            for (int j = 0; j < len; j++){
                up[startpos + (len - j)-1] = j+1;
            }
            startpos = i+1;
            len = 0;
        }   
    }
    reverse(v.begin(), v.end());
    len = 0;
    startpos = 0;
    for (int i = 0; i < n; i++){
        len++;
        if (i == n-1 || v[i] > v[i+1]){
            for (int j = 0; j < len; j++){
                down[startpos + (len - j)-1] = j+1;
            }
            startpos = i+1;
            len = 0;
        }   
    }
    reverse(down, down+n);
    while(m--){
        int a, b;
        cin >> a >> b;
        a--; b--;
        if (up[a] + down[b] > (b - a + 1)){
            cout << "Yes" << endl;
            continue;
        }
        else{
            cout << "No" << endl;
        }
    }
}