#include <bits/stdc++.h>
using namespace std;

int main() {
  int m;
  cin >> m;
  int sum = 0;
  sum += m / 10;
  sum += (m % 10) / 5;
  sum += ((m % 10) % 5);
  cout << sum << "\n";
}
