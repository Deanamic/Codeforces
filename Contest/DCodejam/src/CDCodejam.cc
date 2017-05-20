#include<bits/stdc++.h>
using namespace std;

#include <message.h>
#include "todd_and_steven.h"

const long long MOD = 1000000007;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long nodes = NumberOfNodes();
	long long id = MyNodeId();

	long long tl = GetToddLength();
	long long sl = GetStevenLength();

	if(id == 0){
		long long ans = 0;
		vector<long long> v;
		for(long long i = 0; i < tl; ++i){
			v.push_back(GetToddValue(i));
		}

		for(long long i = 0; i < sl; ++i){
			v.push_back(GetStevenValue(i));
		}

		sort(v.begin(), v.end());
		for(long long i = 0; i < v.size(); ++i){
			ans += i^v[i];
			ans %= MOD;
		}
		cout << ans << endl;
	}

}
