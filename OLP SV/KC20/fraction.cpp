#include <bits/stdc++.h>
using namespace std;

#define ii pair <int, int> 
#define int long long
#define endl '\n'
#define YES "repeating"
#define NO "finite"
#define show_decimal 0

const int N = 1e5 + 5;
const int Base = 30;
const int MOD = 1e9 + 7;

int n, p10[N], hsh[N], pBase[N];
int nPr[N * 10], numCnt[N * 10], denoCnt[N * 10];
vector <int> prime;

void append(int X, int Y, int& i) {
    X /= Y;
    stack <int> st;
    while (X) {
        st.push(X % 10);
        X /= 10;
    }
    while (st.size()) {
        hsh[i] = (hsh[i - 1] * Base % MOD + st.top()) % MOD;
        i++;
        #ifdef show_decimal
        cerr << st.top();
        #endif
        st.pop();
    }
}

int getHash(int i, int j) {
    return (hsh[j] - hsh[i - 1] * pBase[j - i + 1] % MOD + MOD) % MOD;
}

bool check(int i) {
    for (int k = 1; k <= n; k++) {
        int tmp = getHash(i, i + k - 1);
        int j = 1;
        bool ok = 1;
        for (j = 1; i + j * k <= n && ok; j++)
            if (getHash(i + (j - 1) * k, i + j * k - 1) != tmp) 
                ok = 0;
        ok &= (getHash(i, i + n - (i + (j - 1) * k)) == getHash(i + (j - 1) * k, n));
        if (ok)
            return ok;
    }
    return 0;
}

bool brute_force(int X, int Y) {
    X %= Y;
    int i = 1;
    while (i <= 30) {
        if (X == 0)
            return 0;
        int cnt = 1;
        while (p10[cnt] * X < Y) {
            cnt++;
            hsh[i] = hsh[i - 1] * Base % MOD;
            i++;
            #ifdef show_decimal
            cerr << 0;
            #endif
        }
        X *= p10[cnt];
        append(X, Y, i);
        X %= Y;
    }
    n = i - 1;
    for (int i = 1; i <= n; i++)
        if (check(i)) 
            return 1;
    return 0;
}

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
    p10[0] = pBase[0] = 1;
    for (int i = 1; i <= 1000; i++) {
        p10[i] = p10[i - 1] * 10 % MOD;
        pBase[i] = pBase[i - 1] * Base % MOD;
    }
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