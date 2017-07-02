#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, a;
	cin >> n >> a;
	long double interior = 180.0/n;
	if(interior > a) return cout << 1 << ' ' << 2 << ' ' << n << endl, 0;
	if(((n-2)*interior) < a) {
		return cout << 1 << ' ' << 2 << ' ' << 3 << endl, 0;
	}
	interior = a/interior;
	cout << 2 << ' ' << 1 << ' ';
	cout << floor(interior + 0.50) + 2 << endl;
}
