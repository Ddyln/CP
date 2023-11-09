#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define YES "repeating"
#define NO "finite"
#define show_decimal 0

const int N = 1e5 + 5;
const int Base = 30;
const int MOD = 1e9 + 7;

int n, p10[N], hsh[N], pBase[N];

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
        if (show_decimal) cerr << st.top();
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
            if (show_decimal) cerr << 0;
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
    
	while (_nt--) {
        cin >> n;
        int X, Y;
        cin >> X >> Y;
        cout << (brute_force(X, Y) ? YES : NO) << endl;
	}
	
	return 0;
}
