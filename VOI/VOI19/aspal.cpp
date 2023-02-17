#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int M = 1e9 + 7;

int f[2][4][4][4][4][4][4][4][4][4][4][3];
vector <int> v;

string to_st(int n) {
	if (n == 0)
		return "0";
	string res = "";
	while (n) {
		res = char(n % 10 + '0') + res;
		n /= 10;
	}
	return res;
}

bool valid(int l) {
	if (l % 4 == 0) {
		for (int i = 0; i < 10; i++)
			if (v[i] % 4 != 0)
				return 0;
		return 1;
	}
	if (l % 4 == 1) {
		int x = 0;
		for (int i = 0; i < 10; i++)
			if (v[i] % 4 != 0) {
				if (v[i] % 4 == 1)
					x++;
				else
					return 0;
			}
		return (x == 1);
	}
	if (l % 4 == 2) {
		int x = 0;
		for (int i = 0; i < 10; i++)
			if (v[i] % 4 != 0) {
				if (v[i] % 4 == 2)
					x++;
				else
					return 0;
			}
		return (x == 1);	
	}
	int x = 0, tmp[4] = {0, 0, 0, 0};
	for (int i = 0; i < 10; i++) 
		tmp[v[i] % 4]++;
	return ((tmp[2] == 1 && tmp[1] == 1 && !tmp[3]) || (tmp[3] == 1 && !tmp[1] && !tmp[2]));
}

int cal(string s) {
	if (s == "0")
		return 0;
	int n = s.size(), res = 0;
	f[0][0][0][0][0][0][0][0][0][0][0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int m0 = 0; m0 < 4; m0++)
			for (int m1 = 0; m1 < 4; m1++)
				for (int m2 = 0; m2 < 4; m2++)
					for (int m3 = 0; m3 < 4; m3++)
						for (int m4 = 0; m4 < 4; m4++)
							for (int m5 = 0; m5 < 4; m5++)
								for (int m6 = 0; m6 < 4; m6++)
									for (int m7 = 0; m7 < 4; m7++)
										for (int m8 = 0; m8 < 4; m8++)
											for (int m9 = 0; m9 < 4; m9++)
												for (int status = 0; status < 3; status++) {
													int &cur = f[i & 1][m0][m1][m2][m3][m4][m5][m6][m7][m8][m9][status];
													if (!cur)
														continue;
													v[0] = m0;
													v[1] = m1;
													v[2] = m2;
													v[3] = m3;
													v[4] = m4;
													v[5] = m5;
													v[6] = m6;
													v[7] = m7;
													v[8] = m8;
													v[9] = m9;
													if (i && valid(i))
														(res += cur) %= M;
													for (int d = (i == 0 ? 1 : 0); d < 10; d++) {
														int nm0 = m0, nm1 = m1, nm2 = m2, nm3 = m3, nm4 = m4, nm5 = m5, nm6 = m6, nm7 = m7, nm8 = m8, nm9 = m9,
															nstatus = status;
														if (d == 0)
															nm0 = (nm0 + 1) % 4;
														else if (d == 1)
															nm1 = (nm1 + 1) % 4;
														else if (d == 2)
															nm2 = (nm2 + 1) % 4;
														else if (d == 3)
															nm3 = (nm3 + 1) % 4;
														else if (d == 4)
															nm4 = (nm4 + 1) % 4;
														else if (d == 5)
															nm5 = (nm5 + 1) % 4;
														else if (d == 6)
															nm6 = (nm6 + 1) % 4;
														else if (d == 7)
															nm7 = (nm7 + 1) % 4;
														else if (d == 8)
															nm8 = (nm8 + 1) % 4;
														else
															nm9 = (nm9 + 1) % 4;
														if (!status) {
															if (d > s[i] - '0')
																nstatus = 2;
															else if (d < s[i] - '0')
																nstatus = 1;
															else
																nstatus = 0;
														}
														(f[i & 1 ^ 1][nm0][nm1][nm2][nm3][nm4][nm5][nm6][nm7][nm8][nm9][nstatus] += cur) %= M;
													}
													cur = 0;
												}
	for (int m0 = 0; m0 < 4; m0++)
		for (int m1 = 0; m1 < 4; m1++)
			for (int m2 = 0; m2 < 4; m2++)
				for (int m3 = 0; m3 < 4; m3++)
					for (int m4 = 0; m4 < 4; m4++)
						for (int m5 = 0; m5 < 4; m5++)
							for (int m6 = 0; m6 < 4; m6++)
								for (int m7 = 0; m7 < 4; m7++)
									for (int m8 = 0; m8 < 4; m8++)
										for (int m9 = 0; m9 < 4; m9++) {
											v[0] = m0;
											v[1] = m1;
											v[2] = m2;
											v[3] = m3;
											v[4] = m4;
											v[5] = m5;
											v[6] = m6;
											v[7] = m7;
											v[8] = m8;
											v[9] = m9;
											if (valid(n)) 
												for (int status = 0; status < 2; status++) 
													res += f[n & 1][m0][m1][m2][m3][m4][m5][m6][m7][m8][m9][status];
											f[n & 1][m0][m1][m2][m3][m4][m5][m6][m7][m8][m9][0] = 0;
											f[n & 1][m0][m1][m2][m3][m4][m5][m6][m7][m8][m9][1] = 0;
											f[n & 1][m0][m1][m2][m3][m4][m5][m6][m7][m8][m9][2] = 0;
										}
	return res;
}

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
		int l, r;
		cin >> l >> r;
		v.resize(10);
		cout << (cal(to_st(r)) - cal(to_st(l - 1)) + M) % M;
	}

	return 0;
}