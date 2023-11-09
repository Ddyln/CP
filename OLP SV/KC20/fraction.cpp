#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int> 
#define int long long
#define endl '\n'
#define YES "repeating"
#define NO "finite"

const int N = 1e5 + 5;

int n, nPr[N * 10], numCnt[N * 10], denoCnt[N * 10];
vector <int> prime;

void Eratosthenes(int n) {
    nPr[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!nPr[i]) {
            nPr[i] = i;
            prime.push_back(i);
            for (int j = i * i; j <= n; j += i)
                if (nPr[j] == 0)
                    nPr[j] = i;
        }
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	#ifdef lan_ngu
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    #endif

	int _nt; cin >> _nt;
	// int _nt = 1;
    
    Eratosthenes(1000000);
	while (_nt--) {
        cin >> n;
        memset(numCnt, 0, sizeof numCnt);
        memset(denoCnt, 0, sizeof denoCnt);
        vector <ii> v1, v2;
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            while (a > 1) {
                int x = nPr[a];
                while (a % x == 0)
                    a /= x, numCnt[x]++;;
            }
        }
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            while (a > 1) {
                int x = nPr[a];
                while (a % x == 0)
                    a /= x, denoCnt[x]++;;
            }
        }
        bool ok = 0;
        for (int p : prime) {
            if (!denoCnt[p] || p == 2 || p == 5)
                continue;
            if (numCnt[p] < denoCnt[p]) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? YES : NO) << endl;
	}
	
	return 0;
}