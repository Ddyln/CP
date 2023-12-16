//KoJa
#include<bits/stdc++.h>
using namespace std;
#define task "test"
#define SZ(a) (a).begin(), (a).end()
#define SZZ(a, Begin, End) (a) + (Begin), (a) + (Begin) + (End)
#define BIT(x) (1LL << (x))
#define vec vector
#define MASK(x, i) ((x) >> (i))&1
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> ii;

void fastio()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    if(fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
}
const int N = int(1e3) + 5;
int n, m, a[N][N], q, k;
class SegmentTree
{
private:
    int n;
    vec<ll> lz, st;
    void pushDown(int id, int l, int r)
    {
        if(lz[id] == 0) return;
        int mid = (l + r) >> 1;
        st[2 * id] = 1LL * lz[id] * (mid - l + 1);
        st[2 * id + 1] = 1LL * lz[id] * (r - mid);
        lz[2 * id] = lz[id];
        lz[2 * id + 1] = lz[id];
        lz[id] = 0; 
    }
    void update(int u, int v, ll val, int l, int r, int id)
    {
        if((u > v)||(l > r)||(u > r)||(l > v)) return;
        if((u <= l)&&(r <= v))
        {
            st[id] = 1LL * (r - l + 1) * val;
            lz[id] = val;
            return;
        }
        pushDown(id, l, r);
        int mid = (l + r) >> 1;
        update(u, v, val, l, mid, 2 * id);
        update(u, v, val, mid + 1, r, 2 * id + 1);
        st[id] = st[2 * id] + st[2 * id + 1];
    }
    ll getSum(int u, int v, int l, int r, int id)
    {
        if((u > v)||(l > r)||(u > r)||(l > v)) return 0;
        if((u <= l)&&(r <= v)) return st[id];
        pushDown(id, l, r);
        int mid = (l + r) >> 1;
        return getSum(u, v, l, mid, 2 * id) + getSum(u, v, mid + 1, r, 2 * id + 1);
    }
public:
    SegmentTree(int _n = 0)
    {
        this->n = _n;
        st = lz = vec<ll>(4 * n + 10, 0);
    }
    ll getSum(int l, int r) { return getSum(l, r, 1, n, 1);}
    void update(int l, int r, ll val) { return update(l, r, val, 1, n, 1);}
} it[N];
void init()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) cin >> a[i][j];
    cin >> q >> k;
}
void process(const int &tc)
{
    for(int i = 1; i <= n; i++) 
    {
        it[i] = SegmentTree(m);
        for(int j = 1; j <= m; j++)
            it[i].update(j, j, a[i][j]);
    }
    while(q--)
    {
        int t;
        cin >> t;
        if(t == 2) cin >> k;
        else 
        {
            int l1, l2, r1, r2, C;
            cin >> C >> l2 >> l1 >> r2 >> r1;
            ll sum = 0;
            bool dir = 0;
            bool ok = 1;
            for(int i = l1; i <= r1; i++)
            {
                if(!ok) break;
                for(int j = l2; j <= r2; j++)
                {
                    ok &= (a[i][j] >= k);
                    if(!ok) break;
                }
            }
            if(!ok)
            {
                cout << 0 << '\n';
                continue;
            }
            for(int i = l1; i <= r1; i++)
            {
                if(dir == 0)
                {
                    for(int j = l2; j <= r2; j++)
                    {
                        if(sum + a[i][j] - k <= C)
                        {
                            sum += a[i][j] - k;
                            a[i][j] = k;
                        }
                    }
                }
                else 
                {
                    for(int j = r2; j >= l2; j--)
                    {
                        if(sum + a[i][j] - k <= C)
                        {
                            sum += a[i][j] - k;
                            a[i][j] = k;
                        }
                    }
                }
                dir ^= 1;
            }
            cout << sum << '\n';
        }
    }
}
int main()
{
    fastio();
    int tc = 1;
    //cin >> tc;
    for(int T = 0; T < tc; T++)
    {
        init();
        process(T);
    }
    return 0;
}
