#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream fin("gymnastics.in");
    ofstream fout("gymnastics.out");
    int K, N;
    fin >> K >> N;
    vector<vector<int>> sessions;
    for(int i = 0; i < K; i++){
        vector<int> cur;
        for(int j = 0; j < N; j++){
            int a;
            fin >> a;
            cur.push_back(a);
        }
        sessions.push_back(cur);
    }
    int count = 0;
    for(int i = 1; i < N; i++){
        for(int j = i+1; j <= N; j++){
            int first = -1;
            bool exit = false;
            for(vector<int> session : sessions){
                exit = false;
                for(int cow : session){
                    if (cow == i || cow == j){
                        if (first != -1 && first != cow){
                            exit = true;
                            break;
                        }
                        else if(first == cow){
                            break;
                        }
                        else{
                            first = cow;
                            break;
                        }
                    }
                }
                if (exit == true){
                    break;
                }
            }
            if (exit == false){
                count++;
            }
        }
    }
    fout << count;
}