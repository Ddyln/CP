#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

struct Trie {
    struct Node {
        Node* child[2];
        unsigned int cnt;
    };

    Node* GetNode() {
        Node* res = new Node;
        res->child[0] = res->child[1] = NULL;
        res->cnt = 0;
        return res;
    }

    Node* root;
    Trie() {
        root = GetNode();
    };

    void addNum(int n) {
        Node* p = root;
        for (int i = 31; i >= 0; i--) {
            int c = (n >> i) & 1;
            if (p->child[c] == NULL) 
                p->child[c] = GetNode();
            p = p->child[c];
            p->cnt++;
        }
    }

    bool findNum(int n) {
        Node* p = root;
        for (int i = 31; i >= 0; i--) {
            int c = (n >> i) & 1;
            if (p->child[c] == NULL) 
                return 0;
            p = p->child[c];
        }
        return 1;
    }

    int query() {
        Node* p = root->child[0];
        int res = 0;
        for (int i = 30; i >= 0; i--) {
            if (p->child[0] == NULL)
                p->child[0] = GetNode();
            if (p->child[0]->cnt < (1 << i))
                p = p->child[0];
            else {
                if (p->child[1] == NULL)
                    p->child[1] = GetNode();
                p = p->child[1], res += (1 << i);
            }
        }
        return res;
    }
};

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
		// Code here
        int n, q, x = 0;
        cin >> n >> q;
        Trie T{};
        for (int i = 1; i <= n; i++) {
            int a; cin >> a;
            x ^= a;
            T.addNum(a);
        }
        while (q--) {
            int tmp; cin >> tmp;
            x ^= tmp;
            if (!T.findNum(x))
                T.addNum(x);
            cout << T.query() << endl;
        }
	}
	
	return 0;
}