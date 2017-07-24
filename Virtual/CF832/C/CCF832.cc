#include<bits/stdc++.h>
using namespace std;

struct person {
	double x, v;
	int t;
};

int n;
double s;

person vp[100010];

double calc(double m) {
	double up = 1e9, low = 1e9;
	for(int i = 0; i < n; ++i) {
		double x = vp[i].x;
		double v = vp[i].v;

		if(vp[i].t == 1) {
			double t;
			if(m >= x){
				t = (m-x)/(s-v);
				if(x - t*v <= 0)  t = x/v;
				else {
					t += (x - t*v)/(s+v);
				}
			}
			else t = x/v;
					low = min(low, t);
		}
		else {
			double t;
			if(m <= x) {
				t = (x-m)/(s-v);
				if(x + t*v >= 1e6)  t = (1e6-x)/v;
				else {
					t += (1e6 - (x + t*v))/(s+v);
				}

			}
			else {
				t = (1e6 - x)/v;
			}
			up = min(up, t);
		}
	}
	return max(up, low);

}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.setf(ios::fixed);
	cout.precision(14);
	cin >> n >> s;
	for(int i = 0; i < n; ++i){
		cin >> vp[i].x >> vp[i].v >> vp[i].t;
	}

	double l = 0, r = 1e6;
	double ans = 1e18;
	int it = 100;
	while(it--) {
		double m1 = l + (r-l)/3.0;
		double m2 = r - (r-l)/3.0;
		double ans1 = calc(m1);
		double ans2 = calc(m2);
		if(ans1 > ans2) l = m1;
		else r = m2;
		ans = min(ans, min(ans1,ans2));
	}
	cout << ans << endl;

}
