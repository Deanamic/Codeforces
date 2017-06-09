#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	vector<int> v(n),v1(k);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	for(int i = 0; i < k; ++i){
		cin >> v1[i];
	}
	sort(v1.rbegin(), v1.rend());
	int it = 0;
	for(int i = 0; i < n; ++i){
		if(!v[i]) v[i] = v1[it++];
	}
	int aux = v[0];
	for(int i = 1; i < n; ++i){
		if(v[i] <= aux) return cout << "Yes" << endl, 0;
		aux = v[i];
	}
	cout << "No" << endl;
}
