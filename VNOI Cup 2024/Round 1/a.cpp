#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n, cnt[3];

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout); 
        freopen("log.txt", "w", stderr);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
	while (_nt--) {
        cin >> n;
        cnt[1] = cnt[2] = 0;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            if (a == 1) cnt[1]++;
            else if (a == 2) cnt[2]++;
            else {
                cnt[1] += a - 2;
                cnt[2]++;
            }
        }
        cout << cnt[1] / 2 + cnt[2] / 2 << endl;
	}
	
	return 0;
}