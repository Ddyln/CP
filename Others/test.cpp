#include <bits/stdc++.h>
using namespace std;

void radixsort(int a[], int l, int r) {
    int aux[60];
    int *pSrc = a, *pDes = aux, mask = 1;

    for (int d = 0; d < 32; d++) {
        int j = l;
        for (int i = l; i <= r; i++) 
            if (!(mask & pSrc[i])) 
                pDes[j++] = pSrc[i];
        for (int i = l; i <= r; i++)
            if (mask & pSrc[i])
                pDes[j++] = pSrc[i];
        mask <<= 1;
        swap(pSrc, pDes);
    }
}

int main() {
    int a[60] = {3, 2, 4, 1, 10};
    radixsort(a, 0, 4);

    // for (int i = 0; i <= 4; i++)
    //     cout << a[i] << ' ';
    int x = 0b01010101010101010101010101010101;
    cout << (x & 3);
    return 0;   
}