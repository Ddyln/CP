#include <iostream>
#include <malloc.h>
using namespace std;

#define Fname ((string) "test")
#define endl '\n'
typedef int** Matrix;

int n = 0;

Matrix NewMatrix(int n) {
	Matrix m = new int* [n];
	for (int i = 0; i < n; i++) {
		m[i] = new int[n];
		for (int j = 0; j < n; j++) {
			m[i][j] = 0;
		}
	}
	return m;
}

Matrix Multiply(const Matrix& A, const Matrix& B) {
	Matrix C = NewMatrix(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				C[i][j] += A[i][k] * B[k][j];
	return C;
}

void OutputMatrix(const Matrix& A, const int& n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << A[i][j] << ' ';
		cout << endl;
	}
}

void InputMatrix(Matrix& A, const int& n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> A[i][j];
}

Matrix IndexMatrix(int n) {
	Matrix A = NewMatrix(n);
	for (int i = 0; i < n; i++)
		A[i][i] = 1;
	return A;
}

Matrix Pow(const Matrix& A, int k) {
	if (k < 2)
		return (k ? A : IndexMatrix(n));
	Matrix B = NewMatrix(n);
	B = Pow(A, k / 2);
	B = Multiply(B, B);
	return (k % 2 ? Multiply(B, A) : B);
}

signed main() {
	float a = 6.5, b = 7.5;
	cout << &a;
	return 0;


	
	freopen("test.txt", "w", stdout);
	int** p, m, n;
	cin >> m >> n;
	p = new int* [m];
	for (int i = 0; i < m; i++) {
		p[i] = new int[n];
		for (int j = 0; j < n; j++)
			p[i][j] = i * n + j;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++)
			printf("%4d", p[i][j]);
		printf("\n");
	}
	return 0;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen((Fname + ".inp").c_str(), "r", stdin);
	freopen((Fname + ".out").c_str(), "w", stdout);

	Matrix A = NULL;
	cin >> n;
	A = NewMatrix(n);
	InputMatrix(A, n);
	for (int i = 1; i <= 10; i++) {
		cout << "i = " << i << endl;
		OutputMatrix(Pow(A, i), n);
		cout << endl;
	}
	return 0;
}