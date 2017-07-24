#include<bits/stdc++.h>
using namespace std;

string s,r,s1;
int exist = 0;
int v[26] = {0};

bool chk() {
	cin >> s1;
	int l = s1.size() - s.size() + exist;
	if(l < 0) return false;
	if(!exist and l > 0) return false;
	int it1 = 0, it2 = 0;
	while(it1 < s.size() and it2 < s1.size()) {
		if(s[it1] == '?') if(v[s1[it2] - 'a'] == 0) return false;
		else if(s[it1] == '*'){
			for(int i = 0; i < l; ++i){
				if(it2 >= s1.size()) return false;
				if(v[s1[it2] - 'a'] == 1) return false;
				it2++;
			}
			--it2;
		}
		else if(s[it1] != s1[it2]) return false;
		++it2;
		++it1;
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> r >> s;

	for(char c : r) v[c-'a'] = 1;
	for(char c : s) if(c == '*') exist = 1;
	int m;
	cin >> m;
	while(m--) {
		if(chk()) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
