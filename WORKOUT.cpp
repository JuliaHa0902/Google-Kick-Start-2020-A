#include <bits/stdc++.h>
#define NMAX 200000

using namespace std;

int c[NMAX];
double d[NMAX];
int n;

void push (int nHeap, double x) {
	c[nHeap] = 1;
	int child = nHeap;
	int parent = child/2;
	while (parent > 0) {
		if (d[parent] >= x) break;
		d[child] = d[parent];
		child = parent;
		parent = child/2;
	}
	d[child] = x;
}

void update () {
	int parent = 1; int child = parent * 2;
	double dKey = d[1]; int cKey = c[1];
	while (child <= n) {
		if ((child + 1 <= n) && (d[child + 1]/c[child + 1] > d[child]/c[child])) child++;
		if (dKey/cKey > d[child]/c[child]) break;
		d[parent] = d[child]; c[parent] = c[child];
		parent = child; child = parent * 2;
	}
	d[parent] = dKey; c[parent] = cKey;
}

int main () {
	int T, m;
	int a[NMAX];
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> n; cin >> m;
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		
		for (int i = 1; i < n; i ++) {
			d[i] = a[i + 1] - a[i];
		}
		
		for (int i = 1; i < n; i++) 
			push (i, d[i]);
		n--;
		for (int i = 1; i <= m; i++) {
			c[1]++;
			update(); 
		}
	//	cout << d[1] << " " << c[1];
		cout << "Case #" << t << ": " << ceil (d[1]/c[1]) << "\n";
	}
	return 0;
}
