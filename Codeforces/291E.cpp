#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define endl '\n'
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
const int N = 1e5 + 5;

int n, m, pi[3 * N], res, cal[N * 3][26];
string s[N], t;
vector <int> a[N];

int jump(string &s, int k, int cur) {
    if (cur < 1) 
        return 0;
    if (!k) 
        return (s[k] == s[cur]);
    return (s[k] == s[cur] ? k + 1 : jump(s, pi[k], cur));
}

int _cal(int i, int j) {
    if (cal[i][j] < 0) {
        s[0] += ' '; s[0] += char(j + 'a');
        cal[i][j] = jump(s[0], i, m + 2);
        while (s[0].back() != '.')
            s[0].pop_back();
    }
    return cal[i][j];
}

void dfs(int u) {
    int tmp = pi[m + 2];
    for (int i = 0; i < s[u].size(); i++) {
        t += " "; t += s[u][i];
        pi[m + 3] = _cal(pi[m + 2], s[u][i] - 'a');
        res += (pi[m + 3] == m);
        while (t.back() != '.') 
            t.pop_back();
        pi[m + 2] = pi[m + 3];
    }
    for (int &v : a[u]) 
        dfs(v);
    pi[m + 2] = tmp;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef lan_ngu
        freopen((Fname + ".inp").c_str(), "r", stdin);
        freopen((Fname + ".out").c_str(), "w", stdout);
    #endif

    // int _t; cin >> _t;
    int _t = 1;
    while (_t--) {
        cin >> n;
        for (int i = 2; i <= n; i++) {
            int p; cin >> p >> s[i];
            a[p].push_back(i);
        }
        cin >> t;
        m = t.size();
        s[0] = (t += ".");
        for (int i = 0; i <= m; i++)
            for (int j = 0; j < 26; j++)
                cal[i][j] = -1;
        for (int i = 1; i <= t.size(); i++) 
            pi[i] = jump(t, pi[i - 1], i - 1);
        dfs(1);
        cout << res;
    }

    return 0;
}