#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	int x = min(n, k);
	long long ans = 1;
	while(x > 0) {
		ans *= x;
		--x;
	}
	cout << ans << endl;

}
