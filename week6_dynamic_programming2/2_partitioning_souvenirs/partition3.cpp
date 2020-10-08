#include <bits/stdc++.h>
using namespace std;

int dp[23][33];
int n;

int partition3(int w, vector<int> &A) {
  int count=0;
  for(int i=0; i<=n; i++)
  {
  	for(int j=0; j<=w; j++)
  	{
  		if(!i||!j) dp[i][j]=0;
  		else if(A[i-1]<=j)
  			dp[i][j] = max(dp[i-1][j], j+dp[i-1][j-A[i-1]]);
  		else dp[i][j] = dp[i-1][j];
  		if(dp[i][j]==w) count++;
  	}
  }
  if(count==3) return 1;
  return 0;
}

int main() {
  cin >> n;
  int sum=0;
  vector<int> A(n);
  for (size_t i = 0; i < A.size(); ++i) {
    cin >> A[i];
    sum += A[i];
  }
  memset(dp, -1, sizeof(dp));
  if(n<3 || sum%3!=0) cout<<0<<'\n';
  else cout << partition3(sum/3, A) << '\n';
}