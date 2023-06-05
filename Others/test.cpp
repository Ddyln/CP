#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair <int, int> ii;

void bfs(vector <vector <vector <ii>>>& g, vector <vector <int>>& d) {
	int x = 0, y = 0;
	queue <ii> q;
	q.push({x, y});
	d[x][y] = 1;
	while (q.size()) {
		x = q.front().fi, y = q.front().se;
		q.pop();
		for (int i = 0; i < g[x][y].size(); i++) {
			int nx = g[x][y][i].fi, ny = g[x][y][i].se;
			if (d[nx][ny] > 0)
				continue;
			d[nx][ny] = d[x][y] + 1;
			q.push({nx, ny});
		}
	}
}

void Rotate(vector<vector<int>>& a) {
	int m = a.size(), n = a[0].size();
	vector <vector <int>> b(n, vector <int> (m, 0));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			b[j][i] = a[i][j];
	a = b;
}

void BuildGraph(vector <vector <vector <ii>>>& g, vector<vector<int>>& a) {
	int m = a.size(), n = a[0].size();
	g.resize(m);
	for (int i = 0; i < m; i++)
		g[i].resize(n);
	vector <int> row(m, 0), col(n, 0);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			
			int p = row[i] + 1;; 
			if (col[j - 1] < i)
				p = j + 1;
			row[i] = min(j + a[i][j], n - 1);
			if (i == 2 && j == 1) {
				cout << p << ' ' << row[i] << endl;
			}
			for (int k = p; k <= row[i]; k++)
				g[i][j].push_back({i, k});
		
			p = col[j] + 1;; 
			if (row[i - 1] < j)
				p = i + 1;
			col[j] = min(i + a[i][j], m - 1);
			for (int k = p; k <= col[j]; k++) 
				g[i][j].push_back({k, j});
		
		}
}

void BuildGraph_brute_force(vector <vector <vector <ii>>>& g, vector<vector<int>>& a) {
	int m = a.size(), n = a[0].size();
	g.resize(m);
	for (int i = 0; i < m; i++)
		g[i].resize(n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k <= min(n - 1, j + a[i][j]); k++)
				g[i][j].push_back({i, k});
			for (int k = i + 1; k <= min(m - 1, i + a[i][j]); k++)
				g[i][j].push_back({k, j});
		}
}

int minimumVisitedCells(vector<vector<int>>& a, bool bf) {
	int m = a.size(), n = a[0].size();
	if (m == n && m == 1)
		return 1;
	vector <vector <vector <ii>>> g;

	if (!bf)
		BuildGraph(g, a);
	else
		BuildGraph_brute_force(g, a);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << i << ' ' << j << ": ";
			for (int k = 0; k < g[i][j].size(); k++)
				cout << "(" << g[i][j][k].fi << ", " << g[i][j][k].se << "), ";
			cout << endl;
		}
	}
	m = g.size(), n = g[0].size();
	vector <vector <int>> d(m, vector <int> (n, -1));
	bfs(g, d);
	return d[--m][--n];
}

vector <vector <int>> InputTest() {
	fstream cin;
	cin.open("test.inp", ios::in);
	int m = 0, n = 0;
	cin >> m >> n;
	vector <vector <int>> a(m, vector <int> (n, 0));
	for (int i = 0; i < m; i++) 
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	cin.close();
	return a;
}

void MakeTest(int m, int n) {
	fstream cout;
	cout.open("test.inp", ios::out);
	// vector <vector <int>> a(m, vector <int> (n, 0));
	cout << m << ' ' << n << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			// a[i][j] = rand() % 5;
			cout << rand() % 2 << ' ';
		}
		cout << endl;
	}
	cout.close();
}


signed main() {
	srand(time(NULL));
	int _nt = 1000;
	vector <vector <int>> a;


	a = InputTest();
	int res = 0, res_bf = 0;
	res = minimumVisitedCells(a, 0);
	// res_bf = minimumVisitedCells(a, 1);
	cout << res << ' ' << res_bf;

	return 0;


	while (_nt--) {
		MakeTest(2, 2);
		a = InputTest();
		int res = minimumVisitedCells(a, 0);
		int res_bf = minimumVisitedCells(a, 1);
		if (res != res_bf) {
			cout << "WA!!";
			return 0;
		}
	}
	cout << "PASSED";
	return 0;
}