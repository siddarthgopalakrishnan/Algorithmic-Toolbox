#include<bits/stdc++.h>
using namespace std;

int get_change(int m) {
  vector<int> dp(m+1, 0);
  dp[1] = 1, dp[2] = 2, dp[3] = 1, dp[4] = 1;
  if(m<5) return dp[m];
  for(int i = 5; i<=m; i++)
    dp[i] = min(min(dp[i-1], dp[i-3]), dp[i-4]) + 1;
  return dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
