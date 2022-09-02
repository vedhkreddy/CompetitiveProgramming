#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int main(){
    int t;
    cin >> t;
    vector<int> v;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        map<int, int> m;
        vector<int> vv;
        set<int> s;
        for (int j = 0; j < n; j++){
            int a;
            cin >> a;
            vv.push_back(a);
            m[a]++;
            s.insert(a);
        }
        int diversity = s.size();
        for (int j = 0; j < n; j++){
                if (m[vv[j]] > 1){
                auto it = m.find(vv[j]+1);
                if (it != m.end()){
                    diversity++;
                }
                m[vv[j] + 1] = true;
            }
        }
        v.push_back(diversity);
    }
    for (int j : v){
        cout << j << endl;
    }
}