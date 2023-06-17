#include <bits/stdc++.h>
using namespace std;

int ABCD, A, B, C, D;

int f(int X, int Y) {
    int *p1 = &X, *p2 = &Y;
    *p1 += D; *p2 -= A - B;
    return C - *p1 + *p2;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("IPHONE.INP", "r", stdin);
    freopen("IPHONE.OUT", "w", stdout);    
    cin >> ABCD;
    D = ABCD % 10;
    ABCD /= 10;
    C = ABCD % 10;
    ABCD /= 10;
    B =  ABCD % 10;
    ABCD /= 10;
    A = ABCD;    
    cout << 0 << ' ' << A * B * C * D + A - B - C + D;
    return 0;
}