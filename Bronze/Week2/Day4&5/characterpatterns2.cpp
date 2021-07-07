#include <iostream>
#include <vector>
using namespace std;

int main(){
    //https://www.spoj.com/problems/CPTTRN2/
    int N;
    cin >> N;
    vector<pair<int, int>> frames;
    for(int i = 0; i < N; i++){
        int a,b;
        cin >> a >> b;
        frames.push_back(make_pair(a,b));
    }
    for(pair<int, int> p : frames){
        for(int i = 0; i < p.first; i++){
            if (i == 0 || i == p.first - 1){
                for(int j = 0; j < p.second; j++){
                    cout << '*';
                }
                cout << endl;
            }
            else{
                if (p.second > 1){
                    cout << '*';
                    for (int j = 0; j < p.second-2; j++){
                        cout << '.';
                    }
                    cout << '*';
                    cout << endl;
                }
                else{
                    cout << '*' << endl;
                }
            }
        }
        cout << endl;
    }
}