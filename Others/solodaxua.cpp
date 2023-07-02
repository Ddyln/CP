#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define endl '\n'
#define int long long  
int cnt[26];

void solve() {
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < s.size(); i++)
        cnt[s[i] - 'A']++;
    int n = 0, result = 0, count = 0;
    result = 0;
    count = 0;
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        result ^= cnt[i];
        n++;
        if (cnt[i] == 1) count++;
    }
    if ((count == n && result == 1) || (count < n  && result == 0)) {
        cout << "Bronze" << endl;
      }
    else
        cout << "Arka" << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif
    // freopen("test.inp", "w", stdin);
    for (int i = 0; i < 50; i++)
        cout << "A";
    return 0;
    int _nt; cin >> _nt;
    while (_nt--) solve();
    return 0;
}