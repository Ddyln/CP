#include <bits/stdc++.h>
using namespace std;

#define Fname ((string) "test")
#define int long long
#define ii pair <int, int>
#define iii pair <int, ii>
#define fi first
#define se second
#define endl '\n'

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector <TreeNode*> Build(int n, TreeNode* p) {
    vector <TreeNode*> cur;
    if (!n) {
        cur.push_back(NULL);
        return cur;
    }
    for (int i = 0; i <= n; i += 2) {
        p->left = new TreeNode(0);
        p->right = new TreeNode(0);
        vector <TreeNode*> l = Build(i, p->left);
        vector <TreeNode*> r = Build(n - i, p->right);
        for (int i1 = 0; i1 < l.size(); i1++)
            for (int i2 = 0; i2 < r.size(); i2++) {
                cur.push_back(new TreeNode(0, l[i1], r[i2]));
            }
    }
    return cur;
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
		// Code here
        TreeNode* root = new TreeNode(0);
        int n = 3;
        vector <TreeNode*> res = Build(n - 3, root);
	}
	
	return 0;
}