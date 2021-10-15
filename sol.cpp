#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n = 3;
		vector<long long> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		// find the largest element
		long long mx = *max_element(a.begin(), a.end());
		// count the frequency of the maximum element
		int cnt = count(a.begin(), a.end(), mx);
		for (int i = 0; i < n; i++) {
			// if the frequency of the maximum element is greater than 1, then no added
			// votes are needed for the highest vote count, otherwise, it means that there
			// are multiple highest vote count, so we need to add 1 to each of those
			// for the other elements that are not the highest vote count, simply
			// calculate the difference and add 1 to make sure that this new vote count
			// is the highest among all the other 2 candidates
			if (cnt == 1) {
				a[i] = (mx == a[i] ? 0 : mx - a[i] + 1);
			} else {
				a[i] = (mx == a[i] ? 1 : mx - a[i] + 1);
			}
		}
		for (auto& e : a) {
			cout << e << " ";
		}
		cout << '\n';
	}
	return 0;
}
