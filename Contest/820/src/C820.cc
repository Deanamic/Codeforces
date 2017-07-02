#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a,b,l,r;
	cin >> a >> b >> l >> r;
	l--;
	r--;
	vector<char> vc;
	for(int i = 0; i < a; ++i){
		vc.push_back('a' + i);
	}
	while(1) {
		int it = vc.size() - 1;
		for(int i = 0; i < b; ++i) {
			vc.push_back(vc[it]);
		}
		int cnt = 0;
		int add = 0;
		while(cnt < a) {
			bool can = 1;
			for(int i = it; i > it - a; --i) if(vc[i] == 'a' + add) can = 0;
			if(can) {
				++cnt;
				vc.push_back('a'+ add);
			}
			++add;
		}
		if(add == a) break;
	}
	l %= (vc.size());
	r %= (vc.size());
	if(r < l) r += (vc.size());
	vector<int> m(30,0);
	int ans = 0;
	while(l <= r) {
		if(m[vc[l%(vc.size())]-'a'] == 0) ++ans;
		m[vc[l%(vc.size())]-'a'] = 1;
		++l;
	}
	cout << ans << endl;
}
