#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
#define OPEN 1
#define CLOSE 0
const int N = 1e5 + 5;
const int INF = 1e17;

struct RECT {
	int x1, y1, x2, y2;
} rect[N];

int n, res, num[N], low[N], Time, child[N];
vector <int> X, Y, a[N];
vector <iii> ax[2 * N], ay[2 * N];
vector <ii> E;
set <int> curOpen;

bool cmp(const iii &a, const iii &b) {
	if (a.fi < b.fi)
		return 1;
	if (a.fi == b.fi && a.se.fi == OPEN && b.se.fi == CLOSE)
		return 1;
	return 0;
}

void dfs(int u, int par) {
	num[u] = low[u] = ++Time;
	child[u] = 1;
	for (int v : a[u]) 
		if (v != par) {
			if (!num[v]) {
				dfs(v, u);
				child[u] += child[v];
				low[u] = min(low[u], low[v]);
				if (low[v] > num[u])
					E.push_back({u, v});
			} else 
				low[u] = min(low[u], num[v]);
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
		cin >> n;
		for (int i = 1; i <= n; i++) {
			cin >> rect[i].x1 >> rect[i].y1 >> rect[i].x2 >> rect[i].y2;
			swap(rect[i].y1, rect[i].y2);
			X.push_back(rect[i].x1);
			X.push_back(rect[i].x2);
			Y.push_back(rect[i].y1);
			Y.push_back(rect[i].y2);
		}
		sort(X.begin(), X.end());
		X.erase(unique(X.begin(), X.end()), X.end());
		sort(Y.begin(), Y.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		for (int i = 1; i <= n; i++) {
			rect[i].x1 = lower_bound(X.begin(), X.end(), rect[i].x1) - X.begin();
			rect[i].x2 = lower_bound(X.begin(), X.end(), rect[i].x2) - X.begin();
			rect[i].y1 = lower_bound(Y.begin(), Y.end(), rect[i].y1) - Y.begin();
			rect[i].y2 = lower_bound(Y.begin(), Y.end(), rect[i].y2) - Y.begin();
			ax[rect[i].x1].push_back({rect[i].y1, {OPEN, i}});
			ax[rect[i].x1].push_back({rect[i].y2, {CLOSE, i}});
			ax[rect[i].x2].push_back({rect[i].y1, {OPEN, i}});
			ax[rect[i].x2].push_back({rect[i].y2, {CLOSE, i}});
			ay[rect[i].y1].push_back({rect[i].x1, {OPEN, i}});
			ay[rect[i].y1].push_back({rect[i].x2, {CLOSE, i}});
			ay[rect[i].y2].push_back({rect[i].x1, {OPEN, i}});
			ay[rect[i].y2].push_back({rect[i].x2, {CLOSE, i}});
		}

		for (int i = 0; i < X.size(); i++) {
			sort(ax[i].begin(), ax[i].end(), cmp);
			curOpen.clear();
			for (iii &p : ax[i]) {
				if (p.se.fi == OPEN)
					curOpen.insert(p.se.se);
				else {
					int u = p.se.se;
					curOpen.erase(u);
					for (int v : curOpen) {
						a[u].push_back(v);
						a[v].push_back(u);
					}
				}
			}
		}

		for (int i = 0; i < Y.size(); i++) {
			sort(ay[i].begin(), ay[i].end(), cmp);
			curOpen.clear();
			for (iii &p : ay[i]) {
				if (p.se.fi == OPEN)
					curOpen.insert(p.se.se);
				else {
					int u = p.se.se;
					curOpen.erase(u);
					for (int v : curOpen) {
						a[u].push_back(v);
						a[v].push_back(u);
					}
				}
			}
		}
		res = INF;
		for (int i = 1; i <= n; i++)
			if (!num[i]) {
				E.clear();
				dfs(i, i);
				for (ii &tmp : E) {
					int u = tmp.fi, v = tmp.se;
					res = min(res, abs(child[v] - (child[i] - child[v])));
				}
			}
		cout << (res == INF ? -1 : res);
	}

	return 0;
}