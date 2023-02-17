#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc1")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

string name[4];
vector <int> a[4];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		for (int i = 0; i < 4; i++) {
			a[i].clear();
			cin >> name[i];
		}
		for (int i = 0; i < 52; i++) {
			string s1, s2; cin >> s1 >> s2;
			if (s1.size() > 1)
				a[i % 4].push_back(10);
			else
				a[i % 4].push_back(s1[0] - '0');
		}
		int ok = -1;
		for (int i = 0; i < 4; i++) {
			sort(a[i].begin(), a[i].end());
			if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][0] == 2)
				ok = i;
		}
		if (ok < 0)
			cout << "The game has started\n";
		else 
			cout << name[ok] << " is absolute winner\n";
	}

	return 0;
}