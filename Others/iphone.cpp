#include <iostream>
#include <fstream>
using namespace std;

int ABCD, A, B, C, D;

signed main() {
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