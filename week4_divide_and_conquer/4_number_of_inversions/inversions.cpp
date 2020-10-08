#include <bits/stdc++.h>
using namespace std;

long long get_inversions(vector<int> &a, vector<int> &b, size_t left, int ave, size_t right) {
  size_t i = left, j = ave, k = left;
  long long inv_count = 0;
  while (i <= ave - 1 && j <= right) {
    if (a[i] <= a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
      inv_count += ave - i;
    }
  }
  while (i <= ave - 1)
    b[k++] = a[i++];
  while (j <= right)
    b[k++] = a[j++];

  for (i = left; i <= right; i++)
    a[i] = b[i];

  return inv_count;
}

long long merge_sort(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long inv_count = 0;
  if (right <= left) return inv_count;
  size_t ave = left + (right - left) / 2;
  inv_count += merge_sort(a, b, left, ave);
  inv_count += merge_sort(a, b, ave + 1, right);
  inv_count += get_inversions(a, b, left, ave + 1, right);
  return inv_count;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (size_t i = 0; i < a.size(); i++) {
        cin >> a[i];
    }
    vector<int> b(a.size());
    cout << merge_sort(a, b, 0, a.size() - 1) << '\n';
}