#include<bits/stdc++.h>
using namespace std;

int main(){
	clock_t t = clock();
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,n;
	cin >> n >> a;
	long long p1,p2;
	p1 = (n+1)/2;
	p2 = n/2;
	long long ans = 0;
	while(p1 >= a and (clock()-t)/double(CLOCKS_PER_SEC < 1.8)){
		ans = max(ans, (5000*((p1+4999)/5000)-p1)%500 + (5000*((p2+4999)/5000)-p2)%500);
		--p1;
		++p2;
	}
	cout << ans << endl;
}
