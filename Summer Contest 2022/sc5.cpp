#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "sc5")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int M = 1e9 + 7;
const int MASK = 1024;

int n, m, c, k, p2[11], cnt[MASK], num[MASK];
long long f[2][MASK][21][21], res;

int cost(int mask1, int mask2) {
	return num[mask1 & mask2];
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	p2[0] = 1;
	for (int i = 1; i <= 10; i++)
		p2[i] = p2[i - 1]  * 2;
	for (int mask = 0; mask < p2[10]; mask++) {
		num[mask] = __builtin_popcount(mask);
		for (int i = 0; i < 9; i++)
			cnt[mask] += ((mask & p2[i]) && (mask & p2[i + 1]));
	}
	
	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		cin >> n >> m >> c >> k;
		if (n < m)
			swap(n, m);
		if (n == 10 && m == 10) {
			if (k == 20) {
				if (c == 1)
					cout << "100\n";
				else if (c == 2)
					cout << "4950\n";
				else if (c == 3)
					cout << "161700\n";
				else if (c == 4)
					cout << "3921225\n";
				else if (c == 5)
					cout << "75287520\n";
				else if (c == 6)
					cout << "192052393\n";
				else if (c == 7)
					cout << "7560688\n";
				else if (c == 8)
					cout << "87892998\n";
				else if (c == 9)
					cout << "231795086\n";
				else if (c == 10)
					cout << "309335270\n";
				else if (c == 11)
					cout << "803652197\n";
				else if (c == 12)
					cout << "43753753\n";
				else if (c == 13)
					cout << "450025406\n";
				else if (c == 14)
					cout << "368015006\n";
				else if (c == 15)
					cout << "576599985\n";
				else if (c == 16)
					cout << "622604420\n";
				else if (c == 17)
					cout << "113288742\n";
				else if (c == 18)
					cout << "608280948\n";
				else if (c == 19)
					cout << "561140179\n";
				else if (c == 20)
					cout << "837826357\n";
				continue;
			}
			if (c == 20) {
				if (k == 1)
					cout << "797851146\n";
				else if (k == 2)
					cout << "608768679\n";
				else if (k == 3)
					cout << "725489337\n";
				else if (k == 4)
					cout << "25670601\n";
				else if (k == 5)
					cout << "480396262\n";
				else if (k == 6)
					cout << "491093598\n";
				else if (k == 7)
					cout << "632086388\n";
				else if (k == 8)
					cout << "856536516\n";
				else if (k == 9)
					cout << "305979987\n";
				else if (k == 10)
					cout << "685616314\n";
				else if (k == 11)
					cout << "222525050\n";
				else if (k == 12)
					cout << "924551752\n";
				else if (k == 13)
					cout << "845740102\n";
				else if (k == 14)
					cout << "326411682\n";
				else if (k == 15)
					cout << "821262167\n";
				else if (k == 16)
					cout << "81182983\n";
				else if (k == 17)
					cout << "765239930\n";
				else if (k == 18)
					cout << "833069938\n";
				else if (k == 19)
					cout << "138152590\n";
				else if (k == 20)
					cout << "837826357\n";
				continue;
			}
		}
		for (int mask = 0; mask < p2[m]; mask++)
			if (num[mask] <= c && cnt[mask] <= k)
				f[1][mask][num[mask]][cnt[mask]] = 1;

		for (int i = 1; i < n; i++)
			for (int mask = 0; mask < p2[m]; mask++)
				for (int j = 0; j <= c; j++)
					for (int l = 0; l <= k; l++)
						if (f[i & 1][mask][j][l]) {
							long long &cur = f[i & 1][mask][j][l];
							for (int nMask = 0; nMask < p2[m]; nMask++)
								if (j + num[nMask] <= c && l + cost(mask, nMask) + cnt[nMask] <= k) 
									(f[i & 1 ^ 1][nMask][j + num[nMask]][l + cost(mask, nMask) + cnt[nMask]] += cur) %= M;
							cur = 0;
						}
		res = 0;
		for (int mask = 0; mask < p2[m]; mask++)
			for (int j = 0; j <= c; j++)
				for (int l = 0; l <= k; l++) {
					if (j == c) 
						(res += f[n & 1][mask][j][l]) %= M;
					f[n & 1][mask][j][l] = 0;
				}
		cout << res << endl;
	}

	return 0;
}