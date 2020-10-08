#include <bits/stdc++.h>
using namespace std;

int dp[303][10003];
int n, W;

int optimal_weight(int W, const vector<int> &w) {
  for(int i=0; i<=n; i++)
  {
    for(int j=0; j<=W; j++)
    {
      if(i==0||j==0) dp[i][j] = 0;
      else if(w[i-1]<=j)
      {
        dp[i][j] = max(dp[i-1][j], w[i-1]+dp[i-1][j-w[i-1]]);
      }
      else dp[i][j] = dp[i-1][j];
    }
  }
  return dp[n][W];
}

int main() {
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  memset(dp, -1, sizeof(dp));
  cout << optimal_weight(W, w) << '\n';
}