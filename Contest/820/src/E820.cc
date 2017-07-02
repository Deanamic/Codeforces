#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		unsigned long long n1, n2, n3;
		unsigned long long m1, m2, m3;
		unsigned long long s1, s2, s3;
		cin >> n1 >> n2 >> n3 >> m1 >> m2 >> m3 >> s2 >> s3;
		unsigned long long n = n1 * n2 * n3;
		unsigned long long m = m1 * m2 * m3;
		unsigned long long s = s1 * s2 * s3;
		long long ans = 0;
		int f[1000010];
		memset(f, 0, sizeof f);
		for(int i = 2; s1 > 1 ; ++i) {
			if(i * i > s1) {
				f[s1]++;
				break;
			}
			while(s1%i) {
				f[i]++;
				s1 /= i;
			}
		}

		for(int i = 2; s2 > 1 ; ++i) {
			if(i * i > s2) {
				f[s2]++;
				break;
			}
			while(s2%i) {
				f[i]++;
				s2 /= i;
			}
		}

		for(int i = 2; s3 > 1 ; ++i) {
			if(i * i > s3) {
				f[s3]++;
				break;
			}
			while(s3%i) {
				f[i]++;
				s3 /= i;
			}
		}

		long long factors = 1;
		for(int i = 0; i < 1000010; ++i) {
			factors *= (f[i] + 1);
		}

		if(n < 2*s) {
			if(n%2 == 0) {
				unsigned long long tn = n/2;
				if(s % tn == 0) ans += min(m, s/tn);
			}
			else {
				unsigned long long ts = 2*s;
				if(ts % n == 0) ans += min(m, ts/n);
			}
		}

		ans += factors;

		cout << ans << endl;



	}

}
