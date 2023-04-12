#include <bits/stdc++.h>
using namespace std;

int main(){
    int g, n; cin >> g >> n;
    vector<vector<int> > grazings;
    vector<vector<int> > alibis;
    for (int i = 0 ; i < g; i++){
        int a, b, c;
        vector<int> v; cin >> a >> b >> c;
        v = {a, b, c};
        grazings.push_back(v);
    }
    for (int i = 0 ; i < n; i++){
        int a, b, c;
        vector<int> v; cin >> a >> b >> c;
        v = {a, b, c};
        alibis.push_back(v);
    }
    
    int count = n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < g; j++){
            int leg1 = (grazings[j][0] - alibis[i][0]);
            int leg2 = (grazings[j][1] - alibis[i][1]);
            if (hypotf(leg1, leg2) <= float(grazings[j][2] - alibis[i][2])){
                count--;
                break;
            }
            else if(grazings[j][0] == alibis[i][0] && grazings[j][1] == alibis[i][1]){
                count--;
                break;
            }
        }
    }
    cout << count;
}