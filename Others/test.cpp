#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ll long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define pb push_back
#define endl '\n'
#define sz(A) (int) A.size()
#define FOR(i,l,r) for (int i=l;i<=r;i++)
#define FOD(i,r,l) for (int i=r;i>=l;i--)
#define EL printf("\n")
const int MAX = 1e16;
const int bs = 1e9;
typedef vector<int> BigInt;

int n;
string s, t;
vector <string> ans;
stack <char> st;
map <pair <stack <char>, ii>, BigInt> mp;
map <pair <stack <char>, ii>, bool> vis;

void Set(BigInt &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigInt Int(string s) {
	BigInt a;
	while (s.size()%9) s = '0'+s;
	for (int i=0; i<s.size(); i+=9) {
		ll b = 0;
		FOR(j,i,i+9-1) b = b*10+(s[j]-'0');
		a.insert(a.begin(), b);
	}
	Set(a);
	return a;
}

BigInt operator + (BigInt a, BigInt b) {
	BigInt ans;
	Set(a);
	Set(b);
	int c = 0;
	for (int i=0; i<max(a.size(),b.size()); i++) {
		if (i < a.size()) c += a[i];
		if (i < b.size()) c += b[i];
		ans.pb(c%bs);
		c /= bs;
	}
	if (c) ans.pb(c);
	Set(ans);
	return ans;
}

BigInt operator += (BigInt &a, BigInt b) {
    a = a + b;
    return a;
}

bool operator < (BigInt a, BigInt b) {
	if (a.size() != b.size()) return (a.size() < b.size());
	FOD(i,a.size()-1,0)
	if (a[i] != b[i]) return (a[i] < b[i]);
	return false;
}

void Try(int i, int j) {
    vis[{st, {i, j}}] = 1;
    if (j == n) {
        mp[{st, {i, j}}] = Int("1");
    }
    else {
        if (i < n) {
            st.push(s[i]);
            if (!vis[{st, {i + 1, j}}])
                Try(i + 1, j);
            stack <char> tmp = st;
            tmp.pop();
            mp[{tmp, {i, j}}] += mp[{st, {i + 1, j}}];
            st.pop();
        }
        if (st.size() && st.top() == t[j]) {
            st.pop();
            if (!vis[{st, {i, j + 1}}])
                Try(i, j + 1);
            stack <char> tmp = st;
            tmp.push(t[j]);
            mp[{tmp, {i, j}}] += mp[{st, {i, j + 1}}];
            st.push(t[j]);
        }
    }
}

void Find(int i, int j, string command) {
    if (j == n) {
        ans.push_back(command);
    }
    else {
        if (i < n) {
            st.push(s[i]);
            Find(i + 1, j, command + "1");
            st.pop();
        }
        if (st.size() && st.top() == t[j]) {
            st.pop();
            Find(i, j + 1, command + "2");
            st.push(t[j]);
        }
    }
}

void Print(BigInt a) {
	Set(a);
	printf("%d", a.size() == 0 ? 0 : a.back());
	FOD(i,a.size()-2,0) printf("%09d", a[i]);
	EL;
}

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
        cin >> s >> t;
        n = s.size();
        Try(0, 0);
        Print(mp[{st, {0, 0}}]);
        
        if (mp[{st, {0, 0}}] < Int("1001")) {
            Find(0, 0, "");
            for (int i = 0; i < ans.size(); i++)
                cout << endl << ans[i];
        }
	}
	
	return 0;
}