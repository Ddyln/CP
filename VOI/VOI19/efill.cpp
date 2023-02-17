#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 105;

int ld, n;
ii a[N];
double res;

void operator -= (ii &a, ii b) {
	a.fi -= b.fi;
	a.se -= b.se;
}

bool ccw(ii o, ii a, ii b) {
	a -= o; b -= o;
	return a.fi * b.se > a.se * b.fi;
}

bool cmp(const ii &x, const ii &y) {
	return ccw(a[1], x, y);
}

bool md(const ii &x, const ii &y) {
	if (x.se == y.se)
		return x.fi < y.fi;
	return x.se < y.se;
}

int sqr(int n) {
	return n * n;
}

int dist(ii a, ii b) {
	return sqr(a.fi - b.fi) + sqr(a.se - b.se);
}

double dpl(ii O, ii a, ii b) {
	int A = b.se - a.se, B = a.fi - b.fi;
	int C = - A * a.fi - B * a.se;
	return fabs(A * O.fi + B * O.se + C) / sqrt(sqr(A) + sqr(B));
}

double cal(ii B, ii C, ii A, ii D) {
	// double h = dpl(A, B, C), a = sqrt(dist(B, C));
	double a = sqrt(dist(B, C)), h = sqrt(dist(A, ii((B.fi + C.fi) / 2.0, (B.se + C.se) / 2.0)));
	double x = a * sqrt(3) / 6;
	double res = h - x + 2 * sqrt(x * x + a * a / 4);
	if (dpl(D, B, C) < x) {
		res += x - dpl(D, B, C);
		res = min(res, sqrt(dist(D, A)) + sqrt(dist(D, B)) + sqrt(dist(D, C)));
	}
	return res;
}

bool perp(ii a, ii b, ii c, ii d) {
	return ((b.fi - a.fi) * (d.fi - c.fi) + (b.se - a.se) * (d.se - c.se) == 0);
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
		for (int i = 1; i <= n + 2; i++) 
			cin >> a[i].fi >> a[i].se;
		ii tmp = a[2];
		sort(a + 2, a + 1 + n, cmp);
		if (a[2] != tmp)
			reverse(a + 2, a + 1 + n);
		ld = dist(a[1], a[n]);
		res = sqrt(ld);
		for (int i = 2; i < n; i++) {
			res += sqrt(dist(a[i], a[i + 1]));
			ld = max(ld, dist(a[i], a[i + 1]));
		}
		res -= sqrt(ld);
		ii A = a[1], B = a[2], C = a[n + 1], D = a[n + 2];
		if (perp(A, B, C, D)) {
			if (dpl(D, A, B) < dpl(C, A, B))
				res += cal(A, B, C, D);
			else
				res += cal(A, B, D, C);
		} else {
			ii b[4] = {a[1], a[2], a[n + 1], a[n + 2]};
			sort(b, b + 4, md);
			res += sqrt(dist(b[0], b[3]));
		}
		cout << fixed << setprecision(2) << res;
	}

	return 0;
}