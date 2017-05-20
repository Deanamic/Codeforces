#include<bits/stdc++.h>
using namespace std;

#include <message.h>
#include "weird_editor.h"

const long long MOD = 1000000007;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long nodes = NumberOfNodes();
	long long id = MyNodeId();

	long long l = GetNumberLength();

	long long ans = 0;

	long long ints, inte;
	ints = ((id)*l)/nodes;
	inte = ((id+1)*l)/nodes;
	if(id == 0){
		vector<long long> v(10,0);
		v[0] = 1e10;
		long long lstp = 0;
		for(int now = 9; now >= 1; --now){
			for(int i = 1; i < nodes; ++i){
				PutLL(i,lstp);
				Send(i);
			}
			for(long long i = max(ints,lstp); i < inte; ++i){
				long long d = GetDigit(i);
				if(d == now) ++v[now], lstp = i;
			}
			for(int i = 1; i < nodes; ++i){
				Receive(i);
				v[now] += GetLL(i);
			 	lstp = max(lstp, GetLL(i));
			}
		}
		int now = 9;

		while(l){
			while(v[now] == 0) --now;
			if(v[now] >= 2 and l >= 2){
				ans *= 100;
				ans += now * 11;
				v[now] -= 2;
				l -= 2;
			}
			else{
				ans *= 10;
				ans += now;
				--v[now];
				--l;
			}
			ans %= MOD;
		}
		cout << ans << endl;
	}
	else{
		for(long long now = 9; now >= 1; --now){
			Receive(0);
			long long lstp = GetLL(0);
			long long f = 0;
			for(long long i = max(ints, lstp); i < inte; ++i){
				long long d = GetDigit(i);
				if(d == now) ++f, lstp = i;
			}
			PutLL(0,f);
			PutLL(0,lstp);
			Send(0);
		}
	}
	return 0;
}
