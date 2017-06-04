#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin >> n >> k;
	if(n == 0){
 		if(k == 0) {
			cout << "Yes" << endl;
			cout << 1 << ' ' << 1 << endl;
		}
		else if(k == 1) {
			cout << "Yes" << endl;
			cout << 0 << ' ' << 1 << endl;
		}
		else cout << "No" << endl;
	}
	else if(k == 1) {
		cout << "Yes" << endl;
		cout << n << ' ' << 10000000 << endl;
	}
	else if(k == 2) {
		cout << "Yes" << endl;
		cout << n << ' ' << n << endl;
	}else if (k == 0) {
		cout << "Yes" << endl;
		cout << 10000000 << ' ' << 10000000 << endl;
	}
	else if(k == 3)  {
		cout << "Yes" << endl;
		cout << n << ' ' << 0 << endl;
	}
	else cout << "No" << endl;
}
