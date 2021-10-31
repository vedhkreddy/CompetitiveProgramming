#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
    //http://usaco.org/index.php?page=viewproblem2&cpid=1085
    long long N;
    cin >> N;
    long long cowheights[N];
    long long stallheights[N];
    for (long long i = 0; i < N; i++){
        cin >> cowheights[i];
    }
    for (long long i = 0; i < N; i++){
        cin >> stallheights[i];
    }
    sort(cowheights, cowheights + N);
    sort(stallheights, stallheights + N);
    long long perms;
    for (long long i = 0; i < N; i++){
        long long cur = 0;
        for (long long j = 0; j < N; j++){
            if (stallheights[i] >= cowheights[j]){
                cur++;
            }
        }
        cur -= i;
        if (i == 0){
            perms = cur;
        }
        else{
            perms *= cur;
        }
    }
    cout << perms;
}