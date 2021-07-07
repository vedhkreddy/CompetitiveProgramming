#include <iostream>
#include <vector>
using namespace std;

int main(){
    //https://www.spoj.com/status/ns=28160632
    int N;
    cin >> N;
    vector<pair<int, int>> chessboards;
    for(int i  = 0; i < N; i++){
        int a, b;
        cin >> a >> b;
        chessboards.push_back(make_pair(a,b));
    }
    pair<int, int> last = chessboards[N-1];
    char start = '*';
    char cur = '*';
    for(pair<int, int> p : chessboards){
        for(int i = 0; i < p.first; i++){
            for(int j = 0; j < p.second; j++){
                cout << cur;
                if (j == p.second-1){

                }
                else{
                    if (cur == '*'){
                        cur = '.';
                    }
                    else{
                        cur = '*';
                    }                    
                }
            }
            cout << endl;
            if(i % 2 == 0){
                cur = '.';
            }
            else{
                cur = '*';
            }
        }
        if(p == last){
            
        }
        else{
            cout << endl;
        }
        cur = '*';
    }
}
