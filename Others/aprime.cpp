// https://codeforces.com/group/tmdtnfa0l4/contest/400115/problem/A
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 1e3 + 5;
const int P = 1e6 + 5;

int n, lp[P];
vector <int> pr;

void sieve(int n) {
    for (int i = 2; i <= n; i++) {
        if (!lp[i]) {
            lp[i] = i;
            pr.push_back(i);
        }
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && i * pr[j] <= n; j++) 
			lp[i * pr[j]] = pr[j];
    }
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
		sieve(1e6);
		cin >> n;
		for (int i = 1; i <= n; i++) {
			int a, ans = 0; cin >> a;
			for (int j = 0; j < pr.size() && pr[j] * pr[j] <= a; j++)
				for (int l = 0; l < pr.size() && pr[l] * pr[l] * pr[l] <= a; l++) 
					if (a - pr[j] * pr[j] - pr[l] * pr[l] * pr[l] > 0 && lp[a - pr[j] * pr[j] - pr[l] * pr[l] * pr[l]] == a - pr[j] * pr[j] - pr[l] * pr[l] * pr[l])
						ans++;
			cout << ans << endl;
		}
	}
	
	return 0;
}