#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, A, B, C, D, f2[N];
string s;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n >> A >> B >> C >> D >> s;
        int cnt = 0, pos = 0;
        for (char c : s) if (c == '0') cnt++;
        if (cnt == s.size()) {
            cout << "0\n";
            continue;
        }
        if (cnt == 1) {
            if (B == 0) cout << "-1\n";
            else if (s[0] == '0' || s.back() == '0') 
                cout << A << endl;
            else {
                if (B == 1) {
                    if (D == 0) cout << "-1\n";
                    else cout << A + C << endl;
                }
                else {
                    if (D == 0) cout << 2 * A << endl;
                    else cout << min(2 * A, A + C) << endl;
                }
            }
            continue;
        }
        while (s[pos] == '0') pos++;
	}
	
	return 0;
}