#include <bits/stdc++.h>
using namespace std;

bool GreaterOrEqual(string& a, string& b) {
  return(b + a > a + b);
}

string largest_number(vector<string> a, int n) {
  for (size_t i = 1; i < n; i++)
    for (size_t j = 0; j < n - i; j++)
      if (GreaterOrEqual(a[j], a[j + 1]))
        swap(a[j], a[j + 1]);

  stringstream ret; 
  for (size_t i = 0; i < n; i++)
    ret << a[i];

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    cin >> a[i];
  }
  cout << largest_number(a, n);
}
