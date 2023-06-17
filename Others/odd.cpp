#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int n, a[N];

bool cmp(const int &a, const int &b) {
    if (a % 2 == b % 2)
        return 0;
    return (a % 2 > b % 2);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}