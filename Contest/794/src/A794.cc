#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int b,a,c;
	cin >>  a >> b >> c;
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 0; i < n; i++) {
    int x;
		cin >> x;
		if(x > b and x < c) ans ++;
	}
	cout << ans << endl;
}
