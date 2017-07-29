#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> in[200010];
int out[200010];


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i){
		int x;
		cin >> x;
		--x;
		out[x].push_back(i);
		in[i].push_back(x):
	}
}
