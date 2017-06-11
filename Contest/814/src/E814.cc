#include<bits/stdc++.h>
using namespace std;

long long dp[2][52][52][52][52] = {{{{{0}}}}};
//dp states: ith node, 1-plug,2-plug in penultimate and last level.

int d[52];
int n;
const int MOD = 1e9 + 7;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i){
		cin >> d[i];
	}
	dp[1][d[0] == 2][d[0] == 3][d[1] == 2][d[1] == 3] = 1;
	for(int i = 2; i < n; ++i){
		 memset(dp[i&1], 0, sizeof dp[i&1]);
		for(int p1 = 0; p1 <= n; ++p1){
			for(int p2 = 0; p1 + p2 <= n; ++p2){
				for(int c1 = 0; p1 + p2 + c1 <= n; ++c1){
					for(int c2 = 0; p1 + p2 + c1 + c2 <= n; ++c2){
						long long cur = dp[(i-1)&1][p1][p2][c1][c2];
						if(!p1 and !p2) {
							dp[(i-1)&1][c1][c2][0][0] += cur;
							dp[(i-1)&1][c1][c2][0][0] %= MOD;
							continue;
						}

						for(int last_level = 0; last_level < 2; ++last_level){
							long long ways;
							if(last_level) {
								if(p1) ways = p1--;
								else continue;
							}
							else {
								if(p2) p1++, ways = p2--;
								else continue;
							}

							if(d[i] == 2) {
								dp[i&1][p1][p2][c1+1][c2] += cur*ways;
								dp[i&1][p1][p2][c1+1][c2] %= MOD;

								if(c1) {
									dp[i&1][p1][p2][c1-1][c2] += cur*ways*c1;
									dp[i&1][p1][p2][c1-1][c2] %= MOD;
								}

								if(c2) {
									dp[i&1][p1][p2][c1+1][c2-1] += cur*ways*c2;
									dp[i&1][p1][p2][c1+1][c2-1] %= MOD;
								}
							} else {
								//no same level
								dp[i&1][p1][p2][c1][c2+1] += cur*ways;
								dp[i&1][p1][p2][c1][c2+1] %= MOD;

								//connect to a 1 plug
								dp[i&1][p1][p2][c1][c2] += cur*ways*c1;
								dp[i&1][p1][p2][c1][c2] %= MOD;

								if(c1 && c2) {
									dp[i&1][p1][p2][c1][c2-1] += cur*ways*c2*c1;
									dp[i&1][p1][p2][c1][c2-1] %= MOD;
								}

								//connect to 2 1-plug
								if(c1 > 1) {
									dp[i&1][p1][p2][c1-2][c2] += cur*ways*(c1*(c1-1))>>1;
									dp[i&1][p1][p2][c1-2][c2] %= MOD;
								}

								// connect to a 2-plug
								if(c2) {
									dp[i&1][p1][p2][c1+2][c2-1] += cur*ways*c2;
									dp[i&1][p1][p2][c1+2][c2-1] %= MOD;
								}

								//connect to 2 2-plugs
								if(c2 > 1) {
									dp[i&1][p1][p2][c1+2][c2-2] += cur*ways*(c2*(c2-1))>>1;
									dp[i&1][p1][p2][c1+2][c2-2] %= MOD;
								}
							}

							if(last_level) {
								p1++;
							}
							else {
								p2++; p1--;
							}
						}
					}
				}
			}
		}
	}
	cout << dp[(n-1)&1][0][0][0][0] << endl;
}
