#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int a, b;
	cin >> s >> a >> b;
	int n = s.size();
	if(a < b) swap(a,b);
	if(a == 0 and b == 0) return cout << -1 << endl, 0;
	if(s.size() == 1) {
		if(a <= s[0] - '0') cout << a << endl;
		else if (b <= s[0] - '0' and b) cout << b << endl;
		else cout << -1 << endl;
		return 0;
	}
	if(a == b) {
		int all = 0;
		for(int i = 0; i < n; ++i){
			if(s[i] - '0' < a) all = 1;
		}
		for(int i = 0; i < n - all; ++i){
			cout << a;
		}
		cout << endl;
		return 0;

	}

	int all = 0;
	for(int i = 0; i < n; ++i){
		if(s[i] - '0' > b) break;
		if(s[i] - '0' < b) all = 1;
	}
	if(all == 1) {
		for(int i = 0; i < n - 1; ++i){
			cout << a;
		}
		cout << endl;
		return 0;
	}

	int greed = -1;
	for(int i = 0; i < n and greed == -1; ++i){
		if(s[i] - '0' > a) greed = i;
		if(s[i] - '0' > b and s[i] - '0' < a) greed = i;
		if(s[i] - '0' < b) break;
	}
	if(greed != -1){
		for(int i = 0; i < n; ++i){
			if(i <= greed) {
				if(i == 0 and b == 0 and s[i] -'0' < a) continue;
				else cout << (s[i] - '0' >= a ? a : b);
			}
			if(i > greed) cout << a;
		}
		cout << endl;
		return 0;
	}

	int lastl, fs = -1;
	for(int i = 0; i < n and fs == -1; ++i){
		if(s[i] - '0' == a) lastl = i;
		if(s[i] - '0' < b) fs = i;
	}
	if(fs == -1){
		for(int i = 0; i < n; ++i){
			if(i == 0 and b == 0 and s[i] -'0' < a) continue;
			else cout << (s[i] - '0' >= a ? a : b);
		}
		cout << endl;
		return 0;
	}
	for(int i = 0; i < n; ++i){
		if(i < lastl) cout << (s[i] - '0' >= a ? a : b);
		if(i == lastl) cout << b;
		if(i > lastl) cout << a;
	}
	cout << endl;
	return 0;
}
