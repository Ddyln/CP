#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 105;
int n, a[N];
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
        for (int i = 1; i <= n; i++) 
            cin >> a[i];
        while (pq.size())
            pq.pop();
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++) 
                pq.push(__gcd(a[i], a[j]));
        pq.pop();
        cout << pq.top() << endl;
	}
	
	return 0;
}