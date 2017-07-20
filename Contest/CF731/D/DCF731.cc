#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<int> seq[n];
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		while(x--) {
			int y;
			cin >> y;
			--y;
			seq[i].push_back(y);
		}
	}

	int arr[c+1];
	memset(arr, 0, sizeof arr);
	for(int i = 0; i < n-1; ++i) {
		int c1 = -1,c2 = -1;
		int m = min(seq[i].size(), seq[i+1].size());
		for(int j = 0; c1 == -1 and j < m; ++j){
			if(seq[i][j] != seq[i+1][j]) {
				c1 = seq[i][j];
				c2 = seq[i+1][j];
			}
		}
		if(c1 == -1) {
			if(seq[i+1].size() < seq[i].size()) return cout << -1 << endl, 0;
			else ++arr[0];
		}
		else {
			if(c1 < c2) {
				++arr[0];
				--arr[c - c2];
				++arr[c - c1];
			}
			else {
				++arr[c - c1];
				--arr[c - c2];
			}
		}
	}
	int sum = 0;
	for(int i = 0; i < c; ++i){
		sum += arr[i];
		if(sum == n - 1) return cout << i << endl, 0;
	}
	cout << -1 << endl;
}
