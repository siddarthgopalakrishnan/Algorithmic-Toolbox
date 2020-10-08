#include<bits/stdc++.h>
using namespace std;

vector<int> optimal_sequence2(int n) {
  vector<int> dp(n+1, 0);
  dp[1] = 0, dp[2] = 1, dp[3] = 1;
  for(int i = 4; i<=n; i++)
  {
    int temp1 = INT_MAX, temp2 = INT_MAX, temp3 = INT_MAX;
    temp1 = dp[i-1]+1;
    if(i%2==0) temp2 = dp[i/2]+1;
    if(i%3==0) temp3 = dp[i/3]+1;
    dp[i] = min(min(temp1, temp2), temp3);
  }
  vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0 && dp[n]-1 == dp[n/3]) {
      n /= 3;
    } else if (n % 2 == 0 && dp[n]-1 == dp[n/2]) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence2(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
