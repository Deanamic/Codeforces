#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long a,b;
	cin >> a >> b;
	vector<int> bita(61), bitb(61);
	for(int i = 0; i < 61; ++i){
		bita[i] = a%2;
		a /= 2;
	}
	for(int i = 0; i < 61; ++i){
		bitb[i] = b%2;
		b /= 2;
	}
	if(


}
