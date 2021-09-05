#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1013
    ifstream fin("swap.in");
    ofstream fout("swap.out");
    int N, K;
    fin >> N >> K;
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    cout << a << " " << b << " " << c << " " << d << " " << endl;
    vector<int> positions;
    for(int i = 0; i < N; i++){
        positions.push_back(i + 1);
    }
    auto iterator1 = positions.begin();
    auto iterator2 = positions.begin();
    auto iterator3 = positions.begin();
    auto iterator4 = positions.begin();
    for(int i = 0; i < a-1; i++){
        iterator1++;
    }
    for(int i = 0; i < b; i++){
        iterator2++;
    }
    for(int i = 0; i < c-1; i++){
        iterator3++;
    }
    for(int i = 0; i < d; i++){
        iterator4++;
    }
    cout << *iterator1 << " " << *iterator2 << " " << *iterator3 << " " << *iterator4 << " " << endl;
    int back;
    auto copy = positions;
    for(int i = 1; i < 1e9; i++){
        reverse(iterator1, iterator2);
        reverse(iterator3, iterator4);
        if (positions == copy){
            back = i;
            break;
        }
    }
    cout << back;
    int times = K % back;
    for(int i = 0; i < times; i++){
        reverse(iterator1, iterator2);
        reverse(iterator3, iterator4);
    }
    for(int i : positions){
        fout << i << endl;
    }
}