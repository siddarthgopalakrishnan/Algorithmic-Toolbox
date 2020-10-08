#include <bits/stdc++.h>
using namespace std;

int b_search(vector<int> a, int x) {
	int low = 0, high = a.size()-1, mid;
  while (low <= high) {
    mid = low + (high-low)/2;
    if(a[mid] == x)
      return mid+1;
    else if(a[mid] < x)
      low = mid+1;
    else
      high = mid-1;
  }        
  if (x>a[mid]) return mid+1;
  return mid;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points, int n1, int n2) {
  vector<int> cnt(points.size());
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  for(int i=0;i<n2;i++) {
    int l = b_search(starts, points[i]);
    while ((l + 1) < n1 && (starts[l+1] == points[i]))
      l += 1;
    if(l < n1 && starts[l] <= points[i])
      l += 1;
    int r1 = b_search(ends,points[i]);
    while(ends[r1-1] == points[i] && r1>0)
      r1 -= 1;
    cnt[i] = l - r1;
  }
  return cnt;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    cin >> points[i];
  }
  vector<int> cnt = fast_count_segments(starts, ends, points, n, m);
  for (size_t i = 0; i < cnt.size(); i++) {
    cout << cnt[i] << ' ';
  }
}