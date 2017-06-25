#include<bits/stdc++.h>
using namespace std;

int A[55][55];
int n;

bool chk(int u, int v) {
	if(A[u][v] == 1) return false;
	for(int i = 0; i < n; ++i){
		if(i != u) {
			for(int j = 0; j < n; ++j){
				if(j != v) {
					if(A[u][j] + A[i][v] == A[u][v]) return false;
				}
			}
		}
	}
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			cin >> A[i][j];
		}
	}
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n; ++j){
			if(chk(i,j)) return cout << "No" << endl, 0;
		}
	}
	cout << "Yes" << endl;

}
