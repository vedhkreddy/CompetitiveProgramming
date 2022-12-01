#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int first[100001];
int second[100001];
int pos[100001];
int answer[100001];

int main(){
    ifstream cin("cereal.in");
    ofstream cout("cereal.out");
    int N, M;
    cin >> N >> M;
    for (int i = 0 ; i < N; i++){
        cin >> first[i] >> second[i];
    }
    int curanswer = 0;
    for (int i = N-1; i >= 0; i--){
        int x = i;
        int position = first[i];
        while(true){
            if (pos[position] == 0){
                pos[position] = x;
                curanswer++;
                break;
            }
            else if(pos[position] < x){
                break;
            }
            else{
                int y = pos[position];
                pos[position] = x;
                if (position == second[y]){
                    break;
                }
                x = y;
                position = second[y];
            }
        }
        answer[i] = curanswer;
    }
    for (int i = 0; i < N; i++){
        cout << answer[i] << endl;
    }
}