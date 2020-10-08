#include<bits/stdc++.h>
using namespace std;

int dp[103][103];

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  dp[0][0] = 0;
  int n = str1.size(); int m = str2.size();
  for(int i=1; i<=n; i++) dp[i][0] = i;
  for(int i=1; i<=m; i++) dp[0][i] = i;
  for(int i=1; i<=n; i++) {
    for(int j=1;j<=m; j++) {
      if(str1[i-1]==str2[j-1])
        dp[i][j] = dp[i-1][j-1];
      else
      {
        dp[i][j] = 1 + min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]);
      }
    }
  }
  return dp[n][m];
}

int main() {
  string str1;
  string str2;
  cin >> str1 >> str2;
  memset(dp, -1, sizeof(dp));
  cout << edit_distance(str1, str2) << endl;
  return 0;
}
