#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

const int N = 2e5 + 5;
const int INF = 1e18;

int n, k, a[N], f[N];
priority_queue <int, vector <int>, greater <int>> pq, ers;

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
        cin >> n >> k;
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        for (int i = 0; i <= n; i++) {
            pq.push(a[i]);
            if (i >= k) {
                ers.push(a[i - k]);
                while (ers.size() && ers.top() < pq.top())
                    ers.pop();
                while (ers.size() && pq.size() && ers.top() == pq.top()) {
                    ers.pop();
                    pq.pop();
                }
                f[i] = max(f[i - 1], f[i - k] + pq.top());
            }
        }
        // for (int i = 1; i <= n; i++)
        //     cout << f[i] << ' ';
        cout << f[n];
	}
	
	return 0;
}