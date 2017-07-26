#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long x;
	cin >> x;
	long long ans = 2*(x/11);
	x %= 11;
	if(x) ans += 1 + (x > 6);
	cout << ans << endl;
}
