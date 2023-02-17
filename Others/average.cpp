#include <bits/stdc++.h>
using namespace std;
namespace IO {
    const int SIZE = 1 << 23;
    char ibuf[SIZE], *iS, *iT;
    char obuf[SIZE], *oS = obuf, *oT = oS + SIZE - 1;
    bool flush() {
        fwrite(obuf, 1, oS - obuf, stdout);
        oS = obuf;
        return true;
    }
    #define gc() (iS == iT ? (iT = (iS = ibuf) + fread(ibuf, 1, SIZE, stdin), (iS == iT ? EOF : *iS++)) : *iS++)
    #define pc(x) (*oS++ = x) 
    int read() {
        int x = 0, f = 0;
        char c = gc();
        while (!isdigit(c)) f |= c == '-', c = gc();
        while (isdigit(c)) x = 10 * x + c - '0', c = gc();
        return f ? -x : x;
    }
    char qu[55]; int qlen;
    template <class T> void print(T x) {
        if (!x) pc('0');
        if (x < 0) pc('-'), x = -x;
        while (x) qu[++qlen] = x % 10 + '0', x /= 10;
        while (qlen) pc(qu[qlen--]);
    }
    template <class T> void print(T x, char charset) {
        print(x), pc(charset);
    }
    struct Flusher {
        ~Flusher() {
          flush();
        }
    } flusher;
}
using namespace IO;

#define Fname ((string) "test")
#define int long long
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define endl '\n'

const int MOD = 1e9 + 7;
const int N = 205;

int n, res, s, x, f[2][N * N][N], a[N];

signed main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
	#ifdef lan_ngu
	    freopen((Fname + ".inp").c_str(), "r", stdin);
	    freopen((Fname + ".out").c_str(), "w", stdout);
	#endif

    int _nt;
    // cin >> _nt;
    _nt = read();
    // int _nt = 1;
    while (_nt--) {
        // cin >> n >> x;
        n = read();
        x = read();
        s = 0;
        for (int i = 1; i <= n; i++) {
            // cin >> a[i];
            a[i] = read();
            s += a[i];
        }
        f[0][0][0] = 1;
        for (int i = 1; i <= n; i++) {
        	f[i & 1][0][0] = 1;
            for (int j = 1; j <= s; j++)
                for (int k = 1; k <= i; k++) {
                    int &cur = f[i & 1][j][k];
                    int prv = (i & 1 ^ 1);
                    cur = f[prv][j][k];
                    if (j - a[i] >= 0)
                        cur = (cur + f[prv][j - a[i]][k - 1]) % MOD;
                }
        }
        res = 0;
        for (int i = 1; i <= n; i++)
        	res = (res + f[n & 1][i * x][i]) % MOD;
        cout << res << endl;
        if (_nt)
        	memset(f, 0, sizeof(f));
    }

    return 0;
}