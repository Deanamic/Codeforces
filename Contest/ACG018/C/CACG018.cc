#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
struct coin {
	long long a, b;
};
coin v[MAXN];

bool cmp(coin& c1, coin& c2) {
	return c1.a - c1.b < c2.a - c2.b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y,z;
	cin >> x >> y >> z;
	int n = x + y + z;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		int a, b, c;
		cin >> a >> b >> c;
		v[i] = {a-c, b-c};
		ans += c;
	}
	sort(v, v+n, cmp);
	priority_queue<long long> s1, s2;
	long long t = 0;
	long long t1[n], t2[n];
	for(int i = 0; i < n; ++i){
		s1.push(-v[i].b);
		t += v[i].b;
		if(s1.size() > y) {
			t += s1.top();
			s1.pop();
		}
		if(s1.size() == y) 	t1[i] = t;
		else t1[i] = -1e15;

	}
	t = 0;
	for(int i = n-1; i >= 0; --i){
		s2.push(-v[i].a);
		t += v[i].a;
		if(s2.size() > x) {
			t += s2.top();
			s2.pop();

		}
		if(s2.size() == x) t2[i] = t;
		else t2[i] = -1e15;

	}
	long long can = -1e16;

	for(int i = 0; i < n-1; ++i) can = max(can, t1[i] + t2[i+1]);
	if(x == 0) can = max(can, t1[n-1]);
	if(y == 0) can = max(can, t2[0]);

	cout << ans + can << endl;


}
