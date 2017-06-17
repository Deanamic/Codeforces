#include<bits/stdc++.h>
using namespace std;

long long arr[200000];
long long mod = 1e9 + 7;

int b(long long n, long long i) {
	i = min(n-i, i);
	if(i == 0) return 1LL;
	if(i == 1) return arr[1]%4;
	if(arr[i] != -1) return arr[i-1]%4;
	return arr[i] = ((arr[i-1] * (n-i)) / i) ;
}

long long f(int i) {
	if(i%4 == 0) return 0LL;
	if(i%4 == 2) return 2LL;
	return 1LL;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int v[n];
	memset(arr, -1 , sizeof arr);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	arr[1] = n-1;
	long long ans = 0;
	for(int i = 0; i < n; ++i){
		ans += (i%2 ? -1LL : 1LL) * f(b(n-1,i)) * v[i];
		cout << b(n-1,i) << endl;
		ans %= (mod);
	}
	cout << ans << endl;

}
