#include<bits/stdc++.h>
using namespace std;

long long ans[60];
long long n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> ans[i];
	}
	long long op = 0;
	bool found = 1;
	while(found) {
		found = 0;
		for(int i = 0; i < n; ++i){
			if(ans[i] >= n) {
				found = 1;
				long long cur = ans[i]/n;
				ans[i] -= n*cur;
				op += cur;
				for(int j = 0; j < n; ++j) if(j != i) ans[j] += cur;
			}
		}
	}
	cout << op << endl;
}
