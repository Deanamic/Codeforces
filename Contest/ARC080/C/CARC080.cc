#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int a = 0,b = 0,c = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		if(x & 1) a++;
		else if(x & 3) b = 1;
		else c++;
	}
	if(c + 1 >= (a + b)) cout << "Yes" << endl;
	else cout << "No" << endl;
}
