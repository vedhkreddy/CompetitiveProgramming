#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
using namespace std;

bool check(int N, int patientzero, int k, int finalposition[], map<int, pair<int, int>> hoofshakes){
    int curposition[N];
    int shakecounter[N];
    for (int i = 0; i < N; i++){
        curposition[i] = 0;
        shakecounter[i] = 0;
    }
    curposition[patientzero-1] = 1;

    for (auto const& x : hoofshakes){
        bool OnlyFirstInfected = false;
        bool OnlySecondInfected = false;
        if (curposition[x.second.first - 1] == 1 && shakecounter[x.second.first - 1] < k && curposition[x.second.second - 1] == 0){
            OnlyFirstInfected = true;
        }
        else if(curposition[x.second.second - 1] == 1 && shakecounter[x.second.second - 1] < k && curposition[x.second.first - 1] == 0){
            OnlySecondInfected = true;
        }

        if (OnlyFirstInfected == true){
            shakecounter[x.second.first - 1]++;
            curposition[x.second.second - 1] = 1;
        }
        else if (OnlySecondInfected == true) {
            shakecounter[x.second.second - 1]++;
            curposition[x.second.first - 1] = 1;         
        }
        else if(curposition[x.second.second - 1] == 1 && curposition[x.second.first - 1] == 1){
            if (shakecounter[x.second.second - 1] < k){
                shakecounter[x.second.second - 1]++;
            }
            if(shakecounter[x.second.first - 1] < k){
                shakecounter[x.second.first - 1]++;
            }
        }
    }
    for(int i = 0; i < N; i++){
        if (curposition[i] != finalposition[i]){
            return false;
        }
    }
    return true;
}

void solve(int N, int T, int finalposition[], map<int, pair<int, int>> hoofshakes){
    ofstream fout("tracing.out");
    int patientzerocount = 0;
    int min = 1000;
    int max = 0;
    for(int cow = 1; cow <= N; cow++){
        bool yescow = false;
        for(int k = 0; k < T+1; k++){
            if (check(N, cow, k, finalposition, hoofshakes) == true){
                yescow = true;
                if (k < min){
                    min = k;
                }
                if (k > max){
                    max = k;
                }
            }
        }
        if (yescow == true){
            patientzerocount++;
        }
    }
    if (max == T){
        fout << patientzerocount << " " << min << " " << "Infinity";
    }
    else{
        fout << patientzerocount << " " << min << " " << max;
    }
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1037
    ifstream fin("tracing.in");
    int N, T;
    fin >> N >> T;
    int finalposition[N];
    for(int i = 0; i < N; i++){
        char a;
        fin >> a;
        finalposition[i] = int(a) - 48;
    }
    map<int, pair<int, int>> hoofshakes;
    for(int i = 0; i < T; i++){
        int a, b, c;
        fin >> a >> b >> c;
        hoofshakes[a] = make_pair(b, c);
    }
    solve(N, T, finalposition, hoofshakes);
}