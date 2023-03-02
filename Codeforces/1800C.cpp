#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, a, res;
priority_queue <int> pq;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
		freopen((Fname + ".inp").c_str(), "r", stdin);
		freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
		// Code here
        cin >> n;
        res = 0;
        while (pq.size())
            pq.pop();
        for (int i = 1; i <= n; i++) {
            cin >> a;
            if (a)
                pq.push(a);
            else if (pq.size()) {
                res += pq.top();
                pq.pop();
            }
        }
        cout << res << endl;
	}
	
	return 0;
}