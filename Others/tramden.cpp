#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int k;

signed main() {
    int _nt;
    cin >> _nt;
    while (_nt--) {
        cin >> k;
        int ans1 = -1, ans2 = -1;
        for (int n = 1; n * n <= 2 * k; n++) {
            if ((2 * k - 1 + n) % (2 * n - 1) == 0) {
                int m = (2 * k - 1 + n) / (2 * n - 1);
                if (max(n, m) - min(n, m) < max(ans1, ans2) - min(ans1, ans2) || (ans1 == ans2 && ans1 < 0)) {
                    if (min(n, m) > 1)
                        ans1 = n, ans2 = m;
                }
            }
        }
        if (ans1 > ans2)
            swap(ans1, ans2);
        if (min(ans1, ans2) == -1)
            cout << "-1 -1\n";
        else
            cout << ans1 - 1 << ' ' << ans2 - 1 << endl;
    }
    return 0;
}