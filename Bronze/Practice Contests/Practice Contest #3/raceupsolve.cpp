#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

float distancebymax (float b, float x){
    return (2 * pow(b, 2) - pow(x, 2) + x) / 2;
}
float greatestspeed(float K){
    for (int i = 1; i <= K; i++){
        if (i * (i + 1) / 2 >= K){
            return i;
        }
    }
    return 1;
}
float max_speed(float x, float K){
    if (K == 1){
        return 1;
    }
    return floor(sqrt((2 * K + pow(x, 2)) / 2));
}
float findtime(float x, float K){
    float maxspeed = max_speed(x, K);
    float biggestspeed = greatestspeed(K);
    if (maxspeed >= biggestspeed){
        return biggestspeed;
    }
    float time = (2*maxspeed) - x;
    float distance = distancebymax(maxspeed, x);
    float high = maxspeed;
    while (distance < K){
        if (high > x){
            if (distance + ((x + 2) * (high - x + 1) / 2) <= K){
                distance += high;
            }
            else{
                if (high > x){
                    distance += high - 1;
                    time++;
                }
                high -= 1;
            }
        }
        else{
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