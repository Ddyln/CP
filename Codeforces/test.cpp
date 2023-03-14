#include <bits/stdc++.h>
using namespace std;

int main() {
	int *a = new int (5);
	void* p = a;
	p = &a;
	
	return 0;
}