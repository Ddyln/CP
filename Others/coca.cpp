#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

int cnt, n;
string s;

signed main() {
    freopen("test.inp", "r", stdin);
    cin >> s;
    cnt = 1;
    s += '.';
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i - 1])
            cnt++;
        else {
            n += (s[i] != '.') + cnt - 1;
            cnt = 1;
        }
    }
    cout << (n % 2 == 1 ? "Win" : "Lose");
    return 0;
}