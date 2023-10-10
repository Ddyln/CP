#include <iostream>
using namespace std;

void merge(int a[], int aux[], int l, int m, int r) {
    int i, j, k;
    // for (int k = l; k <= r; k++)
    //     aux[k] = a[k];
    i = l, j = m + 1, k = l;
    while (i <= m && j <= r) {
        if (aux[i] <= aux[j]) a[k++] = aux[i++];
        else a[k++] = aux[j++];
    }
    while (i <= m)
        a[k++] = aux[i++];
    while (j <= r)
        a[k++] = aux[j++];
}

void mergeSort(int a[], int aux[], int l, int r) {
    int *pSrc = a, *pDes = aux;
    for (int sz = 1; sz <= r - l; sz *= 2) {
        for (int i = l; i <= r; i += sz * 2) {
            merge(pDes, pSrc, i, min(i + sz - 1, r), min(i + sz * 2 - 1, r));
        }
        swap(pSrc, pDes);
    }
    if (a != pSrc)
        for (int i = l; i <= r; i++)
            a[i] = aux[i];
}

int main() {
    int a[100000] = {0}, aux[100000] = {0}, n = 0;
    freopen("test.inp", "r", stdin);
	freopen("test.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    mergeSort(a, aux, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}