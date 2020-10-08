#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll gcd(ll a, ll b) {
	while (b) {
		ll tmp = a % b;
		a = b;
		b = tmp;
	}
	return a;
}

ll lcm_naive(int a, int b) {
	return a / (ll)(gcd(a, b))* b;
}

int main() {
  int a, b;
  cin >> a >> b;
  if(b>a) swap(a,b);
  cout << lcm_naive(a, b) << endl;
  return 0;
}
