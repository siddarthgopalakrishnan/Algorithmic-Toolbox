#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, capacity;
  cin >> n >> capacity;
  vector<pair<int, int> > value_weight(n);
  vector<pair<double,int> > valperw(n);
  for (int i = 0; i < n; i++) {
    cin >> value_weight[i].first >> value_weight[i].second;
    valperw[i].first = 1.0 * value_weight[i].first / value_weight[i].second;
    valperw[i].second = value_weight[i].second;
  }
  sort(valperw.begin(), valperw.end(),greater<pair<double,int>>());
  double res = 0.0;
  for (int i = 0; i < valperw.size() && capacity>0; i++) {
    res += min(valperw[i].second, capacity) * valperw[i].first;
    capacity -= min(valperw[i].second, capacity);
  }
  cout << fixed << setprecision(4) << res << endl;
}