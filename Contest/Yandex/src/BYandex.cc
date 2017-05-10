#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	unordered_map<string, vector<string> > mcc;
	unordered_map<string, int > mask;
	unordered_map<string, vector<int> > mc;
	cin >> n;
	for(int i = 0; i < n; ++i){
		string s;
		int m;
		cin >> s >> m;
		mc[s].resize(24,-1);
		mask[s] = 0;
		for(int j = 0; j < m; ++j){
			string s1,s2;
			cin >> s1 >> s2;
			mcc[s].push_back(s2);
			for(int k = 0; k < s1.size(); ++k){
				if(s1[k] == '.' and mc[s][k] == -1){
					mc[s][k] = j;
					mask[s] |= (1<<k);
				}
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int bmask = (1<<24)-1;
		int m;
		cin >> m;
		vector<string> qc;
		for(int i = 0; i < m; ++i){
			string s;
			cin >> s;
			qc.push_back(s);
			bmask &= mask[s];

		}
		bool f = 0;
		for(int i = 0; !f and i < 24; ++i){
			if(1<<i & bmask) {
				cout << "Yes";
				for(int j = 0; j < m; ++j){
					cout << ' ' << mcc[qc[j]][mc[qc[j]][i]];
				}
				f = 1;
			}
		}
		if(!f) cout << "No";
		cout << endl;

	}

}
