#include<bits/stdc++.h>
using namespace std;

long long m,b;

long long calc(long long y) {
	long long x = (b - y)*m;
	++y; ++x;
	return ((y*(y-1))/2 * (x)) + ((x*(x-1))/2 * (y));
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> b;
	long long ans = calc(0);
	for(int i = 0; i <= b; ++i) ans = max(calc(i),ans);
	cout << ans << endl;
}
