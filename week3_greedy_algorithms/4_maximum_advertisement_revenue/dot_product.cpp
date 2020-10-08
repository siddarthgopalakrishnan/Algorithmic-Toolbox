#include <bits/stdc++.h>
using namespace std;

long long max_dot_product(vector<int> a, vector<int> b) {
  long long result = 0;
  sort(a.rbegin(), a.rend()); sort(b.rbegin(), b.rend());
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    cin >> b[i];
  }
  cout << max_dot_product(a, b) << endl;
}
