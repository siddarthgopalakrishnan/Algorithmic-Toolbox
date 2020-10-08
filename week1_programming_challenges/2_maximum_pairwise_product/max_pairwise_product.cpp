#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll MaxPairwiseProduct(const vector<int>& numbers) {
    ll max_product = 0;
    int n = numbers.size();

    int pos1=-1, pos2=-1;
    for (int i = 0; i < n; ++i)
    {
    	if((pos1 == -1) || (numbers[i]>numbers[pos1]))
    		pos1 = i;
    }

    for (int i = 0; i < n; ++i)
    {
    	if((i != pos1) && ((pos2 == -1) || (numbers[i]>numbers[pos2])))
    		pos2 = i;
    }

    max_product = ((ll)numbers[pos1]) * ((ll)numbers[pos2]);
    return max_product;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << MaxPairwiseProduct(numbers) << "\n";
    return 0;
}
