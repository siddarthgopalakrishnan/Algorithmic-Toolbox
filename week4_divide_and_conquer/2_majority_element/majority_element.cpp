#include <bits/stdc++.h>
using namespace std;

int get_majority_element(vector<int> &a, int n) {
  map<int, int> Freq; 
  for (size_t i = 0; i < n; i++)
    Freq[a[i]]++;
  for (int i = 0; i <n; i++)
    if (Freq[a[i]] > (n / 2))
      return 1;
  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  cout << (get_majority_element(a, n) != -1) << '\n';
}
