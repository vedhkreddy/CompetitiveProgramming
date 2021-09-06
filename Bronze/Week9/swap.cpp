#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
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
    //doing the a-1 and b because the reverse function is non-inclusive of the second iterator
    advance(iterator1, a-1);
    advance(iterator2, b);
    advance(iterator3, c-1);
    advance(iterator4, d);
    cout << *iterator1 << " " << *iterator2 << " " << *iterator3 << " " << *iterator4 << " " << endl;
    int repeat;
    auto copy = positions;
    for(int i = 1; i < 1e9; i++){
        reverse(iterator1, iterator2);
        reverse(iterator3, iterator4);
        if (positions == copy){
            repeat = i;
            break;
        }
    }
    cout << repeat;
    int times = K % repeat;
    for(int i = 0; i < times; i++){
        reverse(iterator1, iterator2);
        reverse(iterator3, iterator4);
    }
    for(int i : positions){
        fout << i << endl;
    }
}