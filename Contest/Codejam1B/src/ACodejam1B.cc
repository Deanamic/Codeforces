#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int I = 1; I <= T; ++I){
		cout << "Case #" << I  << ": ";
		int n;
		int t = 0;
		cin >> n;
		vector<int> h(n);
		while(n--) {
			int x;
			cin >> x >> h[i];
			t = max(t, x);
		}
		sort(h.begin(), h.end());

		cout.setf(ios::fixed);
		cout.precision(10);
		cout << d/t << endl;


	}

}
