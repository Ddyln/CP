#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const long long INF = (1LL << 60) + 5;
const int N = 2e5 + 5;

struct trie {
	trie *nxt[2];
};

int n, a[N];

trie *newNode() {
	trie *res = new trie;
	res->nxt[0] = res->nxt[1] = nullptr;
	return res;
}

void insert(int bit, int id, trie *cur) {
	for (int i = bit; i >= 0; i--) {
		if (cur->nxt[(a[id] >> i) & 1] == nullptr) 
			cur->nxt[(a[id] >> i) & 1] = newNode(); 
		cur = cur->nxt[(a[id] >> i) & 1];
	}
}

long long get(int bit, int id, trie *cur) {
	long long res = 0;
	for (int i = bit; i >= 0; i--) {
		if (cur->nxt[(a[id] >> i) & 1] == nullptr) {
			res += 1LL << i;
			cur = cur->nxt[(a[id] >> i) & 1 ^ 1];
		} else
			cur = cur->nxt[(a[id] >> i) & 1];
	}
	return res;
}

long long cost(int bit, int l, int r, trie *root) {
	long long res = INF;
	for (int i = l; i <= r; i++) 
		res = min(res, get(bit, i, root));
	return res;
}

long long solve(int bit, int l, int r) {
	if (bit < 0 || l >= r)
		return 0;
	int m = l;
	trie *root = newNode();
	while (m <= r && !(a[m] & (1 << bit))) 
		insert(bit, m++, root);
	long long res = 0;
	if (m > l && m <= r)
		res = cost(bit, m, r, root);
	return res + solve(bit - 1, l, m - 1) + solve(bit - 1, m, r);
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
		cin >> n;
		for (int i = 1; i <= n; i++) 
			cin >> a[i];
		sort(a + 1, a + 1 + n);
		n = unique(a + 1, a + 1 + n) - a - 1;
		cout << solve(29, 1, n);
	}

	return 0;
}