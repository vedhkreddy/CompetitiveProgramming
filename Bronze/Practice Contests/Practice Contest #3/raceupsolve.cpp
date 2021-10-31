#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float distancebymax (float b, float x){
    return (2 * pow(b, 2) - pow(x, 2) + x) / 2;
}

float max_speed(float x, float K){
    return floor(sqrt((2 * K + pow(x, 2) - 3 * x) / 2));
}

float findtime(float x, float K){
    if (x >= K){
        int t = 0;
        for (int i = 1; i <= K; i++){
            if (i * (i + 1) / 2 > K){
                return i;
            }
        }
    }
    float maxspeed = max_speed(x, K);
    float time = (2*maxspeed) - x;
    float distance = distancebymax(maxspeed, x);
    float high = maxspeed;
    while (distance < K){
        bool found = false;
        for(float y = high; y > x; y-= 1){
            if (pow(y, 2) + 2*y - pow(x, 2) - x < K){
                distance += y;
                time+= 1;
                found = true;
                break;
            }
        }
        if (found == false){
            time += ceil((K - distance) / x);
            break;
        }
    }
    return time;
}

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=989
    ifstream fin("race.in");
    ofstream fout("race.out");
    float K;
    float N;
    fin >> K >> N;
    float cur;
    for(float i = 0; i < N; i+= 1){
        fin >> cur;
        fout << findtime(cur, K) << endl;
    }
}