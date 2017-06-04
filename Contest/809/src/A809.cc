#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	double sum = 0;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		sum += x;
	}
	int it = n;
	while(floor(sum/it + 0.5) < k) {
		sum += k;
		++it;
	}
	cout << it - n << endl;

}
