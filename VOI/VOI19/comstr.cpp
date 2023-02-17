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

int m, m1, m2, r, fr[N][26], fibo[100], sth[N], dl[N];
string f[3], s, Clone[N];
vector <int> v;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	// int _nt; cin >> _nt;
	int _nt = 1;
	while (_nt--) {
		cin >> m >> m1 >> m2 >> r;
		cin >> s;
		f[2] = f[1] = "";
		Clone[1] = "a";
		Clone[2] = "b";
		for (int i = 0; i < m2; i++)
			f[2] += s[i];
		for (int i = m2; i < m2 + m1; i++)
			f[1] += s[i];
		int n = 2;
		fibo[1] = fibo[2] = 1;
		do {
			n++;
			fibo[n] = fibo[n - 1] + fibo[n - 2];
			Clone[n] = Clone[n - 1] + Clone[n - 2];
		} while (fibo[n] < m);
		int res = 0, i = 0, j = 0;
		while (i < m) {
			if (Clone[n][j] == 'a') {
				for (int cnt = 0; cnt < m1; cnt++) {
					if (f[1][cnt] != s[i]) {
						dl[cnt]++;
						res++;
					}
					if (i >= m1 + m2)
						sth[cnt]++, fr[cnt][s[i] - 'A']++;
					if (++i == m)
						break;
				}
			} else {
				for (int cnt = 0; cnt < m2; cnt++) {
					if (f[2][cnt] != s[i]) {
						dl[cnt + m1]++;
						res++;
					}
					if (i >= m1 + m2)
						sth[cnt + m1]++, fr[cnt + m1][s[i] - 'A']++;
					if (++i == m)
						break;
				}
			}
			j++;
		}
		for (int i = 0; i < m1 + m2; i++) {
			int tmp = 0;
			for (int j = 0; j < 26; j++)
				tmp = max(tmp, fr[i][j]);
			if (i < m1) {
				if (fr[i][f[1][i] - 'A'] == tmp)
					continue;
			} else {
				if (fr[i][f[2][i - m1] - 'A'] == tmp)
					continue;
			}
			v.push_back(-dl[i] + sth[i] - tmp);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < min(r, (int)v.size()); i++)
			res += v[i];
		cout << res;
	}

	return 0;
}
