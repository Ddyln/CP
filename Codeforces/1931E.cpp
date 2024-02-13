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

int n, m, a[N], b[10];

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
        cin >> n >> m;
        memset(b, 0, sizeof b);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            int cnt = 0;
            while (a[i] % 10 == 0) cnt++, a[i] /= 10;
            b[cnt]++;
            while (a[i]) cnt++, a[i] /= 10;
            s += cnt;
        }
        int i = 0;
        while (true) {
            if (i % 2 == 0) {
                // A
                for (int x = 9; x >= 0; x--) 
                    if (b[x]) {
                        s -= x, b[x]--, b[0]++;
                        break;
                    }
            }
            else {
                // S
                bool ok = 1;
                for (int x = 9; x >= 0; x--)
                    if (b[x]) {
                        b[x]--;
                        ok = 0;
                        break;
                    }
                if (ok) break;
            }
            i++;
        }
        cout << (s >= m + 1 ? "Sasha\n" : "Anna\n");
	}
	
	return 0;
}