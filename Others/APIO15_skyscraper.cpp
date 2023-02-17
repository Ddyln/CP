// https://oj.uz/problem/view/APIO15_skyscraper
#include <bits/stdc++.h>
using namespace std;
 
#define Fname ((string) "io")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 3e4 + 5;
 
int n, m, goal;
bitset <N> d[N], used;
vector <int> a[N];
deque <iii> dq;
 
int find(int u) {
	dq.push_back({0, {u, 0}});
	while (dq.size()) {
		u = dq.front().se.fi;
		int step = dq.front().se.se, total = dq.front().fi;
		dq.pop_front();
		if (u == goal)
			return total;
		if (d[u][step])
			continue;
		d[u][step] = 1;
		if (!used[u]) {
			// used[u] = 1;
			for (int &step : a[u])
				if (!d[u][step])
					dq.push_front({total, {u, step}});
		}
		if (u + step <= n && !d[u + step][step]) 
			dq.push_back({total + 1, {u + step, step}});
		if (u - step > 0 && !d[u - step][step])
			dq.push_back({total + 1, {u - step, step}});
	}
	return -1;
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
		cin >> n >> m;
		int init;
		for (int i = 1; i <= m; i++) {
			int b, p; cin >> b >> p;
			b++;
			a[b].push_back(p);
			if (i == 1)
				init = b;
			else if (i == 2)
				goal = b;
		}	
		cout << find(init);
	}
	return 0;
}