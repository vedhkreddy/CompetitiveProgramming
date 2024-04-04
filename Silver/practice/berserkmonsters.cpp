#include <bits/stdc++.h>
using namespace std;
/*
    Brute force method
        keep count of every monsters ai and dj
        find out how much has subtracted
            for every monster find the next and last
                update
        Problems:
            potentially lasts all n rounds
                n^2 program
    Optimizations
        1) preprocessing
    
    Optimized method
        keep track of which numbers die
            perform an o(1) update
                update tracks new numbers into a queue
        with o(n) preprocessing and o(c) * o(n) deletions at most
            we get o(n) runtime
    
    pseudocode
        use a left array and a right array
        run through list, if something dies add it to array
        while array isn't empty
            update left and rights
            delete from original list

        
            
*/

int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        
    }
}