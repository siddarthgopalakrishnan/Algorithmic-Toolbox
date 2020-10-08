#include<bits/stdc++.h>
using namespace std;

int lcs2(vector<int> &a, vector<int> &b, int n, int m) {
  //write your code here
  int dp[n+1][m+1];
  if(n==0 || m==0) return 0;
  for(int i=0; i<=n; i++) dp[i][0] = 0;
  for(int i=0; i<=m; i++) dp[0][i] = 0;
  for(int i=1; i<=n; i++) {
    for(int j=1;j<=m; j++) {
      if(a[i-1]==b[j-1])
        dp[i][j] = dp[i-1][j-1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  return dp[n][m];
}

int main() {
  size_t n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    cin >> a[i];
  }
  size_t m;
  cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    cin >> b[i];
  }
  cout << lcs2(a, b, n, m) << endl;
}
