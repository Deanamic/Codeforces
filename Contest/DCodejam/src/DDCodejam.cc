#include<bits/stdc++.h>
using namespace std;

#include <message.h>
#include "query_of_death.h"

#define BROKEN -1

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	long long nodes = NumberOfNodes();
	long long id = MyNodeId();

	long long l = GetLength();

	long long ans = 0;
	if(l < 100) nodes = 9;
	if(l < 10) nodes = 2;
	if(id != 0){
		if(id >= nodes) return 0;
		long long bro = -1;
		long long ints, inte;
		ints = ((id-1)*l)/(nodes-1);
		inte = ((id)*l)/(nodes-1);
		long long ans = 0;
		for(long long i = ints; i < inte and bro == -1; ++i){
			int cur = GetValue(i);
			ans += cur;
			for(int j = 0; j < 7; ++j){
				int p = GetValue(i);
				if(p != cur) {
					bro = i;
					break;
				}
			}
		}
		if(bro != -1){
			PutInt(0,BROKEN);
			PutInt(0,ans);
			PutLL(0,bro);
		}else{
			PutInt(0,ans);
		}
		Send(0);
	}
	else{
		for(int k = 1; k < nodes; ++k){
			long long i = Receive(-1);
			int f = GetInt(i);
			if(f == BROKEN){
				ans += GetInt(i);
				long long ints = GetLL(i);
				long long inte = ((i)*l)/(nodes-1);
				for(long long j = ints+1; j < inte; ++j){
					ans += GetValue(j);
				}
			}
			else ans += f;
		}
		cout << ans << endl;

	}

}
