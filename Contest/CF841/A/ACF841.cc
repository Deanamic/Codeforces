#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	string s;
	cin >>s;
	int arr[100] = {};
	for(char c : s) {
		arr[c-'a']++;
		if(arr[c-'a'] > k) return cout << "NO" << endl, 0;
	}
	cout << "YES" << '\n';
}
