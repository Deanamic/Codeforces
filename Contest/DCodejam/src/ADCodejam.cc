#include<bits/stdc++.h>
using namespace std;

#include <message.h>
#include "pancakes.h"

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long nodes = NumberOfNodes();
	long long id = MyNodeId();
	long long stack_size = GetStackSize();
	long long D = GetNumDiners();
	long long dest = D/nodes;
	long long lst = -1;
	long long fst = -1;
	long long ans = 0;
	if(stack_size < 100){
		if(id != 0) return 0;
		for(int i = 0; i < stack_size; ++i){
			long long p = GetStackItem(i);
			if (lst > p) ++ans;
			lst = p;
		}
		cout << ans+1<< endl;
		return 0;
	}
	for(long long i = ((id)*stack_size)/nodes; i < ((id+1)*stack_size)/nodes; i++){
		long long p = GetStackItem(i);
		if(fst == -1) fst = p;
		if (lst > p) ++ans;
		lst = p;
	}
	if(id != 0){
		Receive(id-1);
		ans += GetLL(id-1);
		ans += (GetLL(id-1) > fst? 1 : 0);
		if(fst == -1) --ans;
	}
	if(id == nodes - 1) {cout << ans+1 << endl;}
	else {
		PutLL((id+1)%nodes, ans);
		PutLL((id+1)%nodes, lst);
		Send((id+1)%nodes);
	}
	return 0;


}
