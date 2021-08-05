#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int maxquadrant(pair<int, int> cows[], int a, int b, int N){
    int quadrant1 = 0, quadrant2 = 0, quadrant3 = 0, quadrant4 = 0;
    for(int i = 0; i < N; i++){
        if (cows[i].first > a && cows[i].second > b){
            quadrant1++;
        }
        else if (cows[i].first > a && cows[i].second < b){
            quadrant2++;
        }
        else if(cows[i].first < a && cows[i].second < b){
            quadrant3++;
        }
        else{
            quadrant4++;
        }
    }
    vector<int> quadrants = {quadrant4, quadrant3, quadrant2, quadrant1};
    int max = *max_element(quadrants.begin(), quadrants.end());
    return max;
}

vector<int> check(int a, int b, pair<int, int> cows[], int N, int min){
    multimap<int, int> values;
    int originala = a;
    int originalb = b;
    vector<int> maxvalues;
    a+=2;
    int amax = maxquadrant(cows, a, b, N);
    a-=2;
    b+=2;
    int bmax = maxquadrant(cows, a, b, N);
    b-=2;
    a-=2;
    int amax2 = maxquadrant(cows, a, b, N);
    a += 2;
    b -= 2;
    int bmax2 = maxquadrant(cows, a, b, N);
    maxvalues.push_back(bmax2);
    maxvalues.push_back(amax2);
    maxvalues.push_back(amax);
    maxvalues.push_back(bmax);
    values.insert(make_pair(amax, 1));
    values.insert(make_pair(bmax, 2));
    values.insert(make_pair(amax2, 3));
    values.insert(make_pair(bmax2, 4));
    a = originala;
    b = originalb;

    int maxmin = *min_element(maxvalues.begin(), maxvalues.end());
    
    //if (maxmin > min){
      //  maxmin = min;

        //vector<int> returnlist = {a, b, maxmin};
        //return returnlist;
    //}
    if (values.find(maxmin)->second == 1){
        vector<int> returnlist = {a + 2, b, maxmin};
        return returnlist;
    }
    else if(values.find(maxmin)->second == 2){
        vector<int> returnlist = {a, b + 2, maxmin};
        return returnlist;
    }
    else if(values.find(maxmin)->second == 3){
        vector<int> returnlist = {a - 2, b, maxmin};
        return returnlist;
    }
    else{        
        vector<int> returnlist = {a, b - 2, maxmin};
        return returnlist;       
    }
}

int solve(pair<int, int> cows[], int N, int B){
    int min = 101;
    int a = floor(B/2);
    int b = floor(B/2);
    if (a % 2 != 0){
        a++;
    }
    if (b % 2 != 0){
        b++;
    }
    for(int i = 0; i < 500000; i++){
        vector<int> results = check(a, b, cows, N, min);
        a = results[0];
        b = results[1];
        min = results[2];
    }
    return min;
}


int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=617
    ifstream fin("balancing.in");
    ofstream fout("balancing.out");
    int N, B;
    fin >> N >> B;
    pair<int, int> cows[N];
    for(int i = 0; i < N; i++){
        int x, y;
        fin >> x >> y;
        cows[i] = make_pair(x, y);
    }
    int solution = solve(cows, N, B);
    fout << solution;
}