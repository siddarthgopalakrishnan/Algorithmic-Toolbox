#include<bits/stdc++.h>
using namespace std;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c, int m, int n, int o) {
  //write your code here
  int dp[m+1][n+1][o+1];
  for(int i=0; i<=m; i++)
  {
    for(int j=0; j<=n; j++)
    {
      for(int k=0; k<=o; k++)
      {
        if(i==0 || j==0 || k==0)
        {
          dp[i][j][k] = 0;
          continue;
        }
        else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
        {
          dp[i][j][k] = 1+dp[i-1][j-1][k-1];
          continue;
        }
        else
        {
          dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k]), dp[i][j][k-1]);
        }
      }
    }
  }
  return dp[m][n][o];
}

int main() {
  size_t an;
  cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    cin >> a[i];
  }
  size_t bn;
  cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    cin >> b[i];
  }
  size_t cn;
  cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    cin >> c[i];
  }
  cout << lcs3(a, b, c, an, bn, cn) << endl;
}
