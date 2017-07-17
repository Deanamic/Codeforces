#include<bits/stdc++.h>
using namespace std;

long double ax[100010], by[100010];
long double x,y;
	int n;
long double calc(long double t, int it) {
	long double xx = ax[it] * t + ax[it-1] * (1-t);
	long double yy = by[it] * t + by[it-1] * (1-t);
	//if(it == n) cout << t << endl;
	return xx*xx + yy*yy;
}

long double dist(int it) {
	long double cur = ax[it] * ax[it] + by[it] * by[it];
	if(it) {
		it--;
		cur = min(cur, ax[it] * ax[it] + by[it] * by[it]);
		++it;
	}
	else return cur;
	long double l = 0.0, r = 1.0;
	int IT = 50;
	while(IT--) {
		double m1 = l + (r - l)/3.0;
		double m2 = l + 2.0/3.0*(r - l);
		if(calc(m1,it) > calc(m2,it)) {
			l = m1;
		}
		else r = m2;
	}
	return min(calc(l, it), cur);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(10);

	cin >> n;

	cin >> x >> y;
	long double mind = 1e18, maxd = 0;

	for(int i = 0; i < n; ++i) {
		long double a,b;
		cin >> a >> b;
		ax[i] = (a -= x);
		by[i] = (b -= y);

		mind = min(mind, dist(i));
		maxd = max(maxd, a*a + b*b);
	}
	ax[n] = ax[0];
	by[n] = by[0];
	mind = min(mind, dist(n));
	cout << 4*atan(1) * (maxd - mind) << endl;
}
