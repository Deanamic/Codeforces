#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	bool rated = 0, ch = 0;
	cin >> n;
	int mn = 1e9;
	for (int i = 0; i < n; i++) {
    int a,b;
		cin >> a >> b;
		if(a != b) rated = 1;
		if(a >= mn) ch = 1;
		mn = a;
	}
	if(rated) cout << "rated" << endl;
	else if(ch) cout << "maybe" << endl;
	else cout << "unrated" << endl;

}
