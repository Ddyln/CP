#include <bits/stdc++.h>
using namespace std;

typedef pair <int, int> ii;
#define x first
#define y second
#define endl '\n'

ii a[5];

bool cmp(const ii &a, const ii &b) {
    return a.y < b.y;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("test.inp", "r", stdin);
    int _t;
    cin >> _t;
    while (_t--) {
        for (int i = 1; i <= 3; i++)
            cin >> a[i].x >> a[i].y;
        sort(a + 1, a + 4, cmp);
        if (a[2].y != a[3].y)
            cout << "0\n";
        else
            cout << abs(a[3].x - a[2].x) << endl;
    }
    return 0;
}