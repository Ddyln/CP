#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int> 
#define fi first
#define se second

ii a[1000000] = {{722, 1},
{985, 2},
{380, 1},
{129, 1},
{966, 0},
{310, 2},
{56, 1},
{374, 0}};
int n, m, sum = 0;

int main() {
    #ifdef lan_ngu
        freopen("test.inp", "r", stdin);
    #endif
    n = 8;
    sort(a, a + n, [](ii a, ii b) {
        return a.fi < b.fi;
    });
    for (int i = 0; i < n; i++)
        cout << a[i].fi << ' ' << a[i].se << endl;
    return 0;
}