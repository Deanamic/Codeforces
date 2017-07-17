#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	s += '0';
	long long add = 0;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '0') {
			cout << add;
			add = 0;
		}
		else {
			++add;
		}
	}
	cout << endl;

}
