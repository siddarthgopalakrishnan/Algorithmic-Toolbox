#include <bits/stdc++.h>
using namespace std;

int gcd_naive(int a, int b) {
	if(b == 0) return a;
	// int current_gcd = 1;
	return gcd_naive(b, a%b);
}

int main() {
	int a, b;
	cin >> a >> b;
	if(b>a) swap(a, b);
	cout << gcd_naive(a, b) << endl;
	return 0;
}