#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n, a, b;
	cin >> n >> a >> b;
	if(a > b) return cout << 0 << endl, 0;
	if(n == 1 and a == b) return cout << 1 << endl, 0;
	if(n == 1 and a != b) return cout << 0 << endl, 0;
	cout << (a + (n-1)*b) - (b + (n-1)*a) + 1 << endl;

}
