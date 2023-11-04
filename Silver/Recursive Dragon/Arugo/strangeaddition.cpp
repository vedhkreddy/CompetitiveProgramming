#include <bits/stdc++.h>
using namespace std;
int b[100];
int main()
{
    int n;
    cin >> n;
    bool flag1 = 0, flag2 = 0, flag3 = 0;
    vector <int> a;
    for (int i = 0; i < n; ++ i){
        cin >> b[i];
        int x = b[i];
        if (!x)
            a.push_back(0);
        else if (x < 10){
            if (flag1)
                continue;
            flag1 = 1;
            a.push_back(x);
        }
        else if (x < 100){
            if (flag2)
                continue;
            if (x % 10)
                continue;
            flag2 = 1;
            a.push_back(x);
        }
        else{
            if (flag3)
                continue;
            flag3 = 1;
            a.push_back(100);
        }
    }
    for (int i = 0; i < n; ++ i)
        if (!flag1 && !flag2 && b[i] && b[i] != 100){
            a.push_back(b[i]);
            break;
        }
    cout << a.size() << endl;
    for (int i = 0; i < a.size(); ++ i)
        cout << a[i] << " ";
    puts("");
    return 0;
}