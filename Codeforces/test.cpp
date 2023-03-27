#include <iostream>
using namespace std;

template <class T> void UselessFunction(T n) {
	cout << n;
}

template <class T, class S>
void AnotherUselessFunction(T n, S m) {
	cout << n << ' ' << m << endl;
}

typedef float _float[3];

int main() {
	_float* a = NULL;
	a = (_float*)malloc(2 * sizeof(_float));
	int n = 3, m = 2;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = j + i * n;
	for (int i = 0; i < 3; i++)
		cout << a[i] << ' ' << a + i << endl;
	return 0;
}