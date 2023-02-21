#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

const int N = 2e5 + 5;

int a[N];
int b[N];
int ch[N][10];
int z[N];

struct node {
	int l, r;
	int lazy;
	int val;
} tr[4 * N];

void build(int u, int l, int r) {
	//cout << u << endl;
	if (l == r) {
		tr[u] = {l, r, 0, 0};
		
		return;
	}
	
	tr[u] = {l, r, 0, 0};
	
	int mid = l + r >> 1;
	build(u << 1, l, mid);
	build(u << 1 | 1, mid + 1, r);
}

void pushdown(int u) {
	tr[u << 1].lazy += tr[u].lazy;
	tr[u << 1 | 1].lazy += tr[u].lazy;
	tr[u << 1].val += tr[u].lazy;
	tr[u << 1 | 1].val += tr[u].lazy;
	tr[u].lazy = 0;
}

void modify(int u, int x, int y) {
	//cout << u << endl;
	
	if (tr[u].l >= x && tr[u].r <= y) {
		tr[u].lazy++;
		tr[u].val++;
		
		return;
	}
	
	pushdown(u);
	
	int mid = tr[u].l + tr[u].r >> 1;
	
	if (x <= mid) modify(u << 1, x, y);
	if (y > mid) modify(u << 1 | 1, x, y); 
}

int query(int u, int x) {
	if (tr[u].l == x && tr[u].r == x) {
		return tr[u].val;
	}
	
	if (tr[u].l >= tr[u].r) {
		return 0;
	}
	
	pushdown(u);
	
	int mid = tr[u].l + tr[u].r >> 1;
	
	if (x <= mid) return query(u << 1, x);
	else return query(u << 1 | 1, x);
}

int main() {
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
	int t;
	
	cin >> t;
	
	while (t--) {
		memset(z, 0, sizeof(z));
		memset(ch, 0, sizeof(ch));
		
		int n, q;
		
		scanf("%d%d", &n, &q);
		
		build(1, 1, n);
		
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			
			ch[i][0] = a[i];
			int cnt = 0;
			while (a[i] >= 10) {
				++cnt;
				int x = a[i];
				
				while (x) {
					ch[i][cnt] += x % 10;
					x /= 10;
				}
				
				a[i] = ch[i][cnt];
			}
			
			z[i] = cnt;
		}
		
		while (q--) {
			int op, l, r, x;
			
			scanf("%d", &op);
			
			if (op == 1) {
				scanf("%d%d", &l, &r);
				modify(1, l, r);
			} else {
				scanf("%d", &x);
				int w = query(1, x);
				
				w = min(w, z[x]);
				
				//cout << w << endl;
				
				printf("%d\n", ch[x][w]);
			}
		}
	}
	return 0;
}