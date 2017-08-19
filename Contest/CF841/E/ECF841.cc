#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
long long comb[500][500];
long long fact[500];

bool perf(long long x) {
	long long y = sqrt(x);
	return y*y == x;
}

inline void mod(long long& x) {
	x = ((x%MOD)+MOD)%MOD;
}

void fill() {
	comb[0][0] = 1;
	comb[1][0] = 1;
	comb[1][1] = 1;
	for(int i = 2; i < 500; ++i){
		for(int j = 0; j <= i; ++j){
			if(j == 0) comb[i][j] = 1;
			else if(j == i) comb[i][j] = 1;
			else comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
			mod(comb[i][j]);
		}
	}
	fact[0] = 1;
	for(int i = 1; i < 500; ++i){
		fact[i] = i*fact[i-1];
		mod(fact[i]);
	}
}

inline long long choose(int n, int k) {
	return comb[n][k];
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fill();
	int n;
	cin >> n;
	vector<long long> f;
	vector<long long> r;
	for(int i = 0; i < n; ++i){
		long long x;
		cin >> x;
		for(int j = 0; j <= (int)f.size(); ++j){
			if(j == (int)f.size()) {
				f.push_back(1);
				r.push_back(x);
				break;
			}
			if(perf(x*r[j])) {
				++f[j];
				break;
			}
		}
	}
	vector<vector<long long>> dp(f.size(), vector<long long> (n,0));
	long long sum = f[0];
	dp[0][f[0]-1] = fact[f[0]];
	for(int i = 1; i < (int)f.size(); ++i){
		for(int j = 0; j < sum; ++j){
			if(dp[i-1][j]) {
				for(int k = 1; k <= min(sum+1, f[i]); ++k){
					for(int l = 0; l <= min(j,k); ++l){
						long long cur = choose(j, l) * choose(sum+1 - j, k-l);
						mod(cur);
					    cur *= choose(f[i]-1, k-1);
						mod(cur);
						cur *= dp[i-1][j];
						mod(cur);
						cur *= fact[f[i]];
						mod(cur);
						dp[i][j + f[i] - k - l] +=  cur;
						mod(dp[i][j + f[i] - k - l]);
					}
				}
			}
		}
		sum += f[i];
	}
	cout << dp[f.size()-1][0] << endl;
}
