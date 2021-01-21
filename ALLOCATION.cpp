#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

int main () {
	int T, i, n, b, cnt;
	int a[NMAX];
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n;
		cin >> b;
		for (i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort (a + 1, a + n + 1);
		i = 1; cnt = 0;
		while (i <= n) {
			if (b < a[i]) break;
			cnt++; b -= a[i]; i++;
		}
		cout << "Case #" << t << ": " << cnt << "\n";
	}
}