#include<bits/stdc++.h>
using namespace std;

string s, t;
int szs, szt;

void pr(int x) {
	for(int i = 0; i < szs; ++i) {
		if(s[i] != t[i+x]) cout << i+1 << ' ' ;
	}
}
int chk(int x) {
	int ans = 0;
	for(int i = 0; i < szs; ++i) {
		if(s[i] != t[i+x]) ++ans;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> szs >> szt >> s >> t;
	int mn = szs;
	int it = 0;
	for(int i = 0; i < szt - szs + 1; ++i) {
		int c = chk(i);
		if(c < mn) {
			mn = c;
			it = i;
		}
	}
	cout << mn << endl;
	pr(it);
	cout << endl;

}
