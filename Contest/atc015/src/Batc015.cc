#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin >> s;
	long long ans = 0;
	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'U') ans += 2*i + s.size() - i - 1;
		else ans += i + 2*(s.size() - i - 1);
	}
	cout << ans << endl;

}
