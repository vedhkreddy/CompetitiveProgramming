#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;
    
    while(test_cases--) {
        int n, queries;
        cin >> n >> queries;
        
        vector<int> perm_array(n);
        for(int i = 0; i < n; ++i) cin >> perm_array[i];
        
        for(int i = 0; i < n; ++i) perm_array[i]--;
        
        vector<int> inverse_perm(n);
        for(int i = 0; i < n; ++i) inverse_perm[perm_array[i]] = i;
        
        vector<int> diff_array(n, 0);
        for(int i = 0; i < n; ++i) {
            diff_array[min(i, inverse_perm[i])]++;
            if (max(i, inverse_perm[i]) < n)
                diff_array[max(i, inverse_perm[i])]--;
        }
        
        for(int i = 1; i < n; ++i) diff_array[i] += diff_array[i-1];
        
        string directions;
        cin >> directions;
        
        set<int> issues;
        for(int i = 0; i < n-1; ++i) {
            if(directions[i] == 'L' && directions[i+1] == 'R' && diff_array[i] != 0) {
                issues.insert(i);
            }
        }
        
        while(queries--) {
            int index;
            cin >> index;
            index--;
            
            if(directions[index] == 'L') {
                directions[index] = 'R';
            } else {
                directions[index] = 'L';
            }
            
            if(index > 0 && directions[index-1] == 'L' && directions[index] == 'R' && diff_array[index-1] != 0) {
                issues.insert(index-1);
            } else {
                issues.erase(index-1);
            }
            
            if(index < n-1 && directions[index] == 'L' && directions[index+1] == 'R' && diff_array[index] != 0) {
                issues.insert(index);
            } else {
                issues.erase(index);
            }
            
            if(!issues.empty()) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }
}
