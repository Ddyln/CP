#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 2e5 + 5;

int n, x;
priority_queue <int> q, ers;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	while (_nt--) {
		cin >> n >> x;
        for (int i = 1; i <= n; i++) {
			int tmp; cin >> tmp;
			q.push(tmp);
		}
		while (ers.size())
			ers.pop();
		int res = 0;
		while (q.size()) {
			int cur = q.top();
			q.pop();
			while (ers.size() && cur < ers.top())
				res++, ers.pop();
			if (ers.size() && cur == ers.top()) {
				ers.pop();
				continue;
			}
			if (cur % x == 0)
				ers.push(cur / x);
			else
				res++;
		}
		cout << res + ers.size() << endl;
	}
	
	return 0;
}