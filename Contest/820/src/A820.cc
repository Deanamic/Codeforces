#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int d = 1;
	c -= v0;
	while(c > 0) {
		v0 = min(v1, v0 + a);
		c += l;
		c -= v0;
		++d;
	}

	cout << d << endl;


}
