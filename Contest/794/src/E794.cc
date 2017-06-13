#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans[n];
	memset(ans, 0, sizeof(ans));

	for (int i = 0; i < n-1; ++i) {
		//when I leave an even number of objects + I start
		int v = max(a[i], a[i+1]);
		int left = 2;
		left += min(i , n-i-2) << 1;
		ans[n - left] = max(ans[n - left], v);
	}

	for (int i = 0; i < n-2; i++) {
		//when I leave an odd number of objects + I start
		int v = max(min(a[i+1], a[i]),min(a[i+1], a[i+2]));
		int left = 3;
		left += min(i , n-i-3) << 1;
		ans[n - left] = max(ans[n - left], v);
	}

	//with 2+ movements I can always do better or as good;
	for (int i = 2; i < n; i++) {
		ans[i] = max(ans[i-2], ans[i]);
	}
	ans[n-1] = max(a[0],ans[n-2]);
	//taking everything is the same as taking everything but 1
	for (int i : ans) cout << i << ' ';
	cout << endl;

}
