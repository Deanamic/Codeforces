#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x&1) return cout << "First" << endl, 0;
	}
	cout << "Second" << endl;
}
