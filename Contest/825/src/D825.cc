#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s, t;
	cin >> s >> t;
	int vs[26];
	memset(vs, 0, sizeof vs);
	int have[26];
	memset(have, 0, sizeof have);

	int cnt = 0;
	for(char c : t) vs[c - 'a']++;
	for(char c : s) {
		if(c == '?') cnt++;
		else have[c - 'a']++;
	}
	queue<int> sw;
	while(cnt > 0) {
		for(int i = 0; i < 26; ++i){
			if(have[i] >= vs[i]){
				have[i] -= vs[i];
			}
			else {
				int add = vs[i] - have[i];
				for(int j = 0; j < add; ++j) sw.push(i);
				cnt -= add;
				have[i] = 0;
			}
		}
	}

	for(char c : s) {
		if(c == '?') {
			if(sw.size()) {
				cout << char('a' + sw.front());
				sw.pop();
			}
			else cout << 'a';
		}
		else cout << c;
	}
	cout << endl;

}
