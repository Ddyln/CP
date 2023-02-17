#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1005;

int n, m, a[N][N], b[N][N];
stack <iii> ans;
int fx[] = {-1, -1, -1, 0, 1, 1, 1, 0},
	fy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
queue <ii> q;
set <int> s;
set <int> :: iterator it;

int canPaint(int i, int j) {
	if (i < 1 || i >= n || j < 1 || j >= m)
		return 0;
	s.clear();
	s.insert(a[i][j]);
	s.insert(a[i + 1][j]);
	s.insert(a[i][j + 1]);
	s.insert(a[i + 1][j + 1]);
	if (s.size() == 1)
		return *s.begin();
	if (s.size() > 2)
		return 0;
	it = s.begin();
	it++;
	return (*s.begin() == 0 ? *it : 0);
}

void paint(int x, int y) {
	a[x][y] = a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 0;
}

void bfs() {
	int c;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			if (c = canPaint(i, j)) {
				ans.push({c, {i, j}});
				paint(i, j);
				q.push({i, j});
			}
	while (q.size()) {
		int x = q.front().fi , y = q.front().se;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + fx[i], ny = y + fy[i];
			if (c = canPaint(nx, ny)) {
				ans.push({c, {nx, ny}});
				paint(nx, ny);
				q.push({nx, ny});
			}
		}
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
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> a[i][j];
		bfs();
		bool ok = 1;
		for (int i = 1; i <= n && ok; i++)
			for (int j = 1; j <= m && ok; j++) 
				ok &= (a[i][j] == 0);
		if (!ok)
			cout << -1;
		else {
			cout << ans.size() << endl;
			while (ans.size()) {
				cout << ans.top().se.fi << ' ' << ans.top().se.se << ' ' << ans.top().fi << endl;
				ans.pop();
			}
		}
	}
	return 0;
}