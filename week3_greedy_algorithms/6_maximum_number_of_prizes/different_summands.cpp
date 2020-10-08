#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  for (int i = 1; n; i++) {
    if (n - i > i) {
      summands.push_back(i);
      n -= i;
    } else {
      summands.push_back(n);
      break;
    }
  }
  return summands;
}

int main() {
  int n;
  cin >> n;
  vector<int> summands = optimal_summands(n);
  cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    cout << summands[i] << ' ';
  }
}
