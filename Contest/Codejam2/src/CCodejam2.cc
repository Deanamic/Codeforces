#include<bits/stdc++.h>
using namespace std;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int I = 1; I <= T; ++I){
		cout << "Case #" << I <<": ";
		int r,c;
		cin >> r >> c;
		vector<vector<int>> v(r, vector<int> (c));
		for(int i = 0; i < r; ++i){
			for(int j = 0; j < c; ++j){
				char c;
				cin >> c;
				if(c == '.') v[i][j] = 0;
				else if(c == '#') v[i][j] = -1;
				else v[i][j] = 1;
			}
		}
	}

}
