#include <iostream>
#include <fstream>
using namespace std;

int pref[1001][1001];
int arr[1001][1001];
int main(){
    //ifstream cin("forestqueries.in");
    int n, q;
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            char a;
            cin >> a;
            if(a == '*'){
                arr[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1;j <= n; j++){
            pref[i][j] = pref[i-1][j] + pref[i][j-1] - pref[i-1][j-1] + arr[i][j];
        }
    }
    for (int i = 0; i < q; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        cout << pref[c][d] + pref[a][b] - pref[c][b] - pref[a][d] << endl;
    }
}