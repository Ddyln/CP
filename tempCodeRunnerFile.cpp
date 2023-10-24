#include <iostream>
using namespace std;

void sieve(int N) {
    int *a = new int [N];
    for (int i = 2; i < N; i++)
        *(a + i) = 1;
    for (int i = 2; i < N; i++)
        if (*(a + i))
            for (int j = 1; j * i < N; j++)
                *(a + i * j) = 0;
    for (int i = 2; i < N; i++)
        if (*(a + i))
            cout << " " << i;
    delete[] a;
}

int main() {
    sieve(20);
    return 0;
}