#include <bits/stdc++.h>
using namespace std;
namespace IO {
    const int SIZE = 1 << 23;
    char ibuf[SIZE], *iS, *iT;
    char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
    bool flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return true;
    }
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    #define pc(x) (*oS++ = x) 
    int read() {
        int x = 0, f = 0;
        char c = gc();
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = 10 * x + c - '0', c = gc();
        return f ? -x : x;
    }
    char qu[55]; int qlen;
    template <class T> void print(T x) {
        if (!x) pc('0');
        if (x < 0) pc('-'), x = -x;
        while (x) qu[++qlen] = x % 10 + '0', x /= 10;
        while (qlen) pc(qu[qlen--]);
    }
    template <class T> void print(T x, char charset) {
        print(x), pc(charset);
    }
    struct Flusher {
        ~Flusher() {
          flush();
        }
    } flusher;
}
using namespace IO;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

int n, m, q, par[N][20], tIn[N], tOut[N], Time;
vector <int> a[N], f[N][20], res;

void dfs(int u) {
	tIn[u] = ++Time;
	for (int i = 1; i <= 16; i++) {
		par[u][i] = par[par[u][i - 1]][i - 1];
		merge(f[u][i - 1].begin(), f[u][i - 1].end(), f[par[u][i - 1]][i - 1].begin(), f[par[u][i - 1]][i - 1].end(), back_inserter(f[u][i]));
		while (f[u][i].size() > 10)
			f[u][i].pop_back();
	}

	for (int v : a[u])
		if (v != par[u][0]) {
			par[v][0] = u;
			dfs(v);
		}
	tOut[u] = ++Time;
}

bool isAncestor(int u, int v) {
	return (tIn[u] <= tIn[v] && tOut[u] >= tOut[v]);
}

int lca(int u, int v) {
	if (isAncestor(u, v))
		return u;
	if (isAncestor(v, u))
		return v;
	for (int i = 16; i >= 0; i--)
		if (par[u][i] != 0 && !isAncestor(par[u][i], v))
			u = par[u][i];
	return par[u][0];
}

void get(int u, int v) {
	if (u == v)
		return;
	for (int i = 16; i >= 0; i--)
		if (par[u][i] != 0 && !isAncestor(par[u][i], v)) {
			a[0].clear();
			merge(res.begin(), res.end(), f[u][i].begin(), f[u][i].end(), back_inserter(a[0]));
			swap(res, a[0]);
			while (res.size() > 10)
				res.pop_back();
			u = par[u][i];
		}
	a[0].clear();
	merge(res.begin(), res.end(), f[u][0].begin(), f[u][0].end(), back_inserter(a[0]));
	swap(res, a[0]);
	while (res.size() > 10)
		res.pop_back();
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
		// cin >> n >> m >> q;
		n = read();
		m = read();
		q = read();
		for (int i = 1; i < n; i++) {
			// int u, v; cin >> u >> v;
			int u, v; u = read(); v = read();
			a[u].push_back(v);
			a[v].push_back(u);
		}
		for (int i = 1; i <= m; i++) {
			// int tmp; cin >> tmp;
			int tmp; tmp = read();
			f[tmp][0].push_back(i);
		}
		for (int i = 1; i <= n; i++) {
			sort(f[i][0].begin(), f[i][0].end());
			while (f[i][0].size() > 10)
				f[i][0].pop_back();
		}
		dfs(1);
		while (q--) {
			// int u, v, MAX; cin >> u >> v >> MAX;
			int u, v, MAX; u = read(); v = read(); MAX = read();
			int k = lca(u, v);
			res.clear();
			get(u, k);
			get(v, k);
			a[0].clear();
			merge(res.begin(), res.end(), f[k][0].begin(), f[k][0].end(), back_inserter(a[0]));
			swap(res, a[0]);
			while (res.size() > 10)
				res.pop_back();
			cout << min(MAX, (int)res.size()) << ' ';
			for (int i = 0; i < min(MAX, (int)res.size()); i++)
				cout << res[i] << ' ';
			cout << endl;
		}
	}

	return 0;
}