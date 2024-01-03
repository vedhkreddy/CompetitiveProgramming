#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
#define N 10005
 
struct Point {
    int x, y;
    Point(int x = 0, int y = 0):x(x), y(y) {}
    bool operator < (const Point & b) const {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};
 
Point a[N];
int b[N];
 
int main() {
    int n, i, j, bn, x, y;
    scanf("%d", &n);
    for (i = 0; i < n; ++i) {
        scanf("%d %d", &x, &y);
        if (x > y) swap(x, y);
        a[i] = Point(x, y);
    }
    sort(a, a + n);
    bn = 0;
    for (i = 0; i < n; ++i) {
        b[bn++] = a[i].y;
        for (j = i + 1; j < n && a[j].x <= a[i].y; ++j);
        i = j - 1;
    }
    printf("%d\n", bn);
    for (i = 0; i < bn - 1; ++i)
        printf("%d ", b[i]);
    printf("%d\n", b[bn - 1]);
    return 0;
}