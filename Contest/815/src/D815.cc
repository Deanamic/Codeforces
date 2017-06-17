#include<bits/stdc++.h>
using namespace std;

struct card {
	long long a,b,c;
	bool operator < (const card& C) const {
		return a > C.a;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, p, q, r;
	cin >> n >> p >> q >> r;
	long long mp = 0 , mq = 0 , mr = 0;
	card C[n+1];
	C[n] = {0 , 0 , 0};
	multiset<int> cq, cr;
	for(int i = 0; i < n; ++i){
		cin >> C[i].a >> C[i].b >> C[i].c;
		mp = max(C[i].a , mp);
		mq = max(C[i].b , mq);
		mr = max(C[i].c , mr);
		cq.insert(
	}

	sort(C, C + n);
	long long ans = 0;
	ans += (p - mp) * (((q - mq) * r) + ((r - mr) * q));
	long long minq = C[0].b;
	long long minr = C[0].c;
	for(int i = 0; i < n; ++i) {
		cout << ans << endl;
		minq = max(minq, C[i].b);
		minr = max(minr, C[i].c);
		ans += (C[i].a - C[i+1].a) * (q - mq) * (r - minr);
		cout << ans << endl;
		ans += (C[i].a - C[i+1].a) * (r - mr) * (q - minq);
	}
	cout << ans << endl;
}
