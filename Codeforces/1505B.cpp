#include <bits/stdc++.h>
using namespace std;

signed main() {
    int n = 0;
    cin >> n;
    while (n > 9) {
        int tmp = n;
        n = 0;
        while (tmp) {
            n += tmp % 10;
            tmp /= 10;
        }
    }
    cout << n;
    return 0;
}