#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout << 10000 << ' ' << 10000 << endl;
	for(int i = 0; i < 10000; ++i){
		cout << 10000-i << ' ';
	}
	cout << endl;
	for(int i = 0; i < 10000; ++i){
			cout << 1 << ' ' << 10000 << ' ' << (random()%10000) + 1 << endl;
	}


}
