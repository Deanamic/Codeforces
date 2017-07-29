#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long k;
	cin >> k;
	long long ans[50];
	long long times = (k+49)/50;
	for(int i = 0; i < 50; ++i) {
		ans[i] = (49) + times - 1;
	}
	ans[49]++;
	long long extra = 50*times - k;
	while(extra--) {
		int itmx = 0;
		int vlmx = 0;
		for(int i = 0; i < 50; ++i) {
			if(ans[i] > vlmx) {
				vlmx = ans[i];
				itmx = i;
			}
		}
		for(int i = 0; i < 50; ++i) {
			if(i == itmx) ans[i] -= 50;
			else ++ans[i];
		}
	}
	cout << 50 << endl;
	for(int i = 0; i < 50; ++i){
		cout << ans[i] << ' ';
	}
	cout << endl;

}
