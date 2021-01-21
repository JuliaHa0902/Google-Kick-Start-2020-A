#include <bits/stdc++.h>

using namespace std;

int main () {
	int T, n, k, p;
	int a[200][200];
	int f[200][2000];
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n; cin >> k; cin >> p;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				cin >> a[i][j];
			}
		}
		
		for (int i = 0; i <= p; i++) f[0][i] = 0;
		for (int i = 0; i <= n; i++) f[i][0] = 0;
		
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j <= p; j++) {
				int sum = 0;
				f[i][j] = f[i - 1][j];
				for (int l = 1; l <= k; l++) {
					sum += a[i][l];
					if (j - l < 0) break;
					f[i][j] = max (f[i][j], f[i - 1][j - l] + sum);
				}
			}
		}
		cout << "Case #" << t << ": " << f[n][p] << "\n";
	}
}