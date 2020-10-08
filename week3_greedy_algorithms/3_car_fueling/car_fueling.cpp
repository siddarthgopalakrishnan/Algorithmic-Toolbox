#include <bits/stdc++.h>
using namespace std;

int compute_min_refills(int dist, int tank, vector<int>& stops) {
  int refils = 0, currentpos = 0, nextpos=0;
  stops.push_back(dist);
  stops.insert(stops.begin(), 0);
  if(stops[1] > tank) return -1;
  while(stops[currentpos] + tank < dist) {
    currentpos = nextpos;
    while((nextpos < stops.size()-1) && (stops[nextpos+1] <= (stops[currentpos]+tank))) {
      nextpos = nextpos+1;
    }
    if (nextpos == currentpos)
      return -1;
    if (stops[currentpos]+tank < dist)
      refils += 1;
  }
  return refils;
}


int main() {
  int d, n, m;
  cin >> d >> m >> n;
  vector<int> stops(n);
  for (int i = 0; i < n; ++i)
    cin >> stops[i];

  cout << compute_min_refills(d, m, stops) << "\n";

  return 0;
}
