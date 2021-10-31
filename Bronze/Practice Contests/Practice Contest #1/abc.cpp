#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1059
    vector<int> numbers;
    for(int i = 0; i < 7; i++){
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[6] - a - b;
    cout << a << ' ' << b << ' ' << c << endl;
}