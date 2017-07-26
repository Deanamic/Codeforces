#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int v[100010] = {};
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		++v[x];
	}
	int cnt = 0;
	int ans = 0;
	for(int i = 0; i < 100005; ++i) {
		if(v[i] > 1) {
			if(v[i]%2) ans += v[i]/2;
			else {
				ans += (v[i]-1)/2;
				++cnt;
			}
		}
	}
	cout << n - 2*(ans + (cnt+1)/2) << endl;
}
