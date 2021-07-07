#include <iostream>
#include <vector>
using namespace std;

int main(){
    //https://www.spoj.com/problems/CPTTRN3/
    int N;
    cin >> N;
    vector<pair<int, int>> grids;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        grids.push_back(make_pair(a, b));
    }
    for(pair<int, int> p : grids){
        for(int i = 0; i < (p.first*3) + 1; i++){
            if (i % 3 == 0){
                for(int j = 0; j < (p.second * 3) + 1; j++){
                    cout << '*';
                }
                cout << endl;
            }
            else{
                cout << '*';
                for(int j = 0; j < p.second; j++){
                    cout << "..*";
                }
                cout << endl;
            }
        }
        cout << endl;
    }
}