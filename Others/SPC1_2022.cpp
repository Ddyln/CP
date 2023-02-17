// https://www.hackerrank.com/contests/seriescontest-re-up/challenges/spc1-spring-contest-2022
#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "io")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

int n;
stack <int> st;

struct trie {
	int cnt[2];
	trie *nxt[2];
};

trie *newNode() {
	trie *res = new trie;
	res->cnt[0] = res->cnt[1] = 0;
	return res;
}

void insert(int k, trie *cur) {
	while (k) {
		st.push(k % 2); 
		k /= 2;
	}
	while (st.size() < 30)
		st.push(0);
	for (int i = 29; i >= 0; i--) {
		cur->cnt[st.top()]++;
		if (cur->cnt[st.top()] == 1)
			cur->nxt[st.top()] = newNode();
		cur = cur->nxt[st.top()];
		st.pop();
	}
}

int find(int k, trie *cur) {
	int res = 0;
	for (int i = 29; i >= 0; i--) {
		if (cur->cnt[0] >= k) 
			cur = cur->nxt[0];
		else {
			k -= cur->cnt[0];
			cur = cur->nxt[1];
			res += 1 << i;
		}
	}
	return res;
}

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
		cin >> n;
		trie *root = newNode();
		while (n--) {
			int t, k; cin >> t >> k;
			if (t == 1)
				insert(k, root);
			else
				cout << find(k, root) << endl;
		}
	}

	return 0;
}