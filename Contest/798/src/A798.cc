#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	int i = 0,j = s.size() -1;
	int dif = 0;
	while(i <= j){
		if(s[i] != s[j]) ++dif;
		++i;
		--j;
	}
	if(dif == 1 or (s.size()%2 and dif == 0)) cout << "YES" << endl;
	else cout << "NO" << endl;
}
