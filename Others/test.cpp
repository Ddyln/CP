#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int maxn = 1000000 + 5; //10^6 + 5
bool is_prime[maxn];

void Eratosthenes(int n){
    for (int i = 2; i <= n; i++)
        is_prime[i] = true;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int min_prime[maxn] = { 0 };

void sieve(int n)
{
    for (int i = 2; i * i <= n; ++i) {
        if (min_prime[i] == 0) {
            for (int j = i * i; j <= n; j += i) {
                if (min_prime[j] == 0) {
                    min_prime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (min_prime[i] == 0) {
            min_prime[i] = i;
        }
    }
}

// n^k
long long Pow(int n, int k) {
    if (k < 1) return 1;
    if (k == 1) return n % MOD;
    long long ans = Pow(n, k / 2);
    (ans *= ans) %= MOD;
    return (k % 2 == 1 ? ans * n % MOD : ans);
}

int main()
{
    freopen("test.inp", "r", stdin);
    Eratosthenes(maxn);
    sieve(maxn);
    int n, m;
    cin >> n;
    vector<int> a(maxn, 0);
    vector<int> b(maxn, 0);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        while (k != 1)
        {
            a[min_prime[k]]++;
            k /= min_prime[k];
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int k;
        cin >> k;
        while (k != 1)
        {
            b[min_prime[k]]++;
            k /= min_prime[k];
        }
    }
    unsigned long long S = 1;
    for (int i = 0; i < maxn; i++)
    {
        if(is_prime[i])
        {
            (S *= Pow(i, min(a[i], b[i]))) %= MOD;
        }
    }
    cout << S;
    return 0;
}