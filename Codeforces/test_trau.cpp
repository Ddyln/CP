#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
// #define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 2e5 + 5;
const int MASK = (1 << 26) - 1;

int n, a[N], res = 0, cnt[26];
string s[N];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".ans").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		// Code here
        cin >> n;
        for (int i = 1; i <= n; i++) 
			cin >> s[i];
		for (int i = 1; i < n; i++)
			for (int j = i + 1; j <= n; j++) {
				string tmp = s[i] + s[j];
				int numChar = 0;
				memset(cnt, 0, sizeof(cnt));
				for (int k = 0; k < tmp.size(); k++)
					if (++cnt[tmp[k] - 'a'] == 1)
						numChar++;
				if (numChar == 25) {
					bool ok = 1;
					for (int k = 0; k < 26; k++) 
						if (cnt[k] != 0 && cnt[k] % 2 == 0)
							ok = 0;
					res += ok;
				}
			}
		cout << res;
	}
	
	return 0;
}