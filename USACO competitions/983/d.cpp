#include <bits/stdc++.h>
using namespace std;

class DeleteOnly_DLL {
public:
    vector<int> values;
    vector<int> prev;
    vector<int> next;
    int pointer;

    DeleteOnly_DLL(int size) {
        values.resize(size);
        prev.resize(size);
        next.resize(size);

        for (int i = 0; i < size; i++) {
            prev[i] = (i + size - 1) % size;
            next[i] = (i + 1) % size;
        }

        pointer = 0;
    }

    int current() {
        return values[pointer];
    }

    void set_and_move(int val) {
        values[pointer] = val;
        pointer = next[pointer];
    }

    void erase() {
        if (prev[pointer] != -1) {
            next[prev[pointer]] = next[pointer];
        }
        if (next[pointer] != -1) {
            prev[next[pointer]] = prev[pointer];
        }

        int next_id = next[pointer];
        prev[pointer] = next[pointer] = -1;
        pointer = next_id;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    bool hasMultipleTests = true;
    if (hasMultipleTests) cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n, -1);
        p[1] = 0;

        int r = 2;
        while (true) {
            cout << "? " << 1 << " " << r << endl;
            cout.flush();

            int res; cin >> res;
            if (res == -1) exit(2226);

            if (res == 1) {
                p[r] = 0;
                r++;
            }
            else break;
        }

        int tentacle_count = r - 1;

        DeleteOnly_DLL tentacles = DeleteOnly_DLL(tentacle_count);
        for (int i = 0; i < tentacle_count; i++) {
            tentacles.set_and_move(i + 1);
        }

        p[r] = tentacles.current();
        tentacles.set_and_move(r);
        r++;

        while (r < n) {
            cout << "? " << tentacles.current() << " " << r << endl;
            cout.flush();

            int res; cin >> res;
            if (res == -1) exit(2226);

            if (res == 1) {
                tentacles.erase();
            }
            else {
                p[r] = tentacles.current();
                tentacles.set_and_move(r);
                r++;
            }
        }

        cout << "!";
        for (int i = 1; i < n; i++) {
            cout << " " << p[i];
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}
