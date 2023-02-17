#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'
const int N = 1e5 + 5;

struct trie {
	trie *nxt[26];
	bool isEnd;
};

int n;
string s[N];

trie *newNode() {
	trie *res = new trie;
	for (int i = 0; i < 26; i++)
		res->nxt[i] = nullptr;
	res->isEnd = 0;
	return res;
}

void insert(trie *cur, string s) {
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == nullptr)
			cur->nxt[s[i] - 'a'] = newNode();
		cur = cur->nxt[s[i] - 'a'];
	}
	cur->isEnd = 1;
}

bool find(trie *cur, string s) {
	for (int i = 0; i < s.size(); i++) {
		if (cur->nxt[s[i] - 'a'] == nullptr)
			return 0;
		cur = cur->nxt[s[i] - 'a'];
	}
	return cur->isEnd;
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
		bool ok = 0;
		for (int i = 1; i <= n; i++) {
			cin >> s[i];
			ok |= (s[i].size() == 1 || (s[i].size() == 2 && s[i][0] == s[i][1]) || (s[i].size() == 3 && s[i][0] == s[i][2]));
		}
		if (ok)
			cout << "YES\n";
		else {
			trie *root = newNode();
			for (int i = 1; i <= n && !ok; i++) {
				if (s[i].size() == 2) {
					string tmp = ""; tmp += s[i][1]; tmp += s[i][0];
					ok |= find(root, tmp);
					for (int j = 0; j < 26 && !ok; j++) 
						ok |= find(root, tmp + string(1, j + 'a'));
				} else {
					string tmp = ""; tmp += s[i][2]; tmp += s[i][1];
					ok |= find(root, tmp) | find(root, tmp + string(1, s[i][0]));
				}
				insert(root, s[i]);
			}
			cout << (ok ? "YES\n" : "NO\n");
		}	
	}

	return 0;
}