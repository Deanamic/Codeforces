#include<bits/stdc++.h>
using namespace std;

struct shop{
	int a, b, c;

	bool operator < (const shop& s) {
		return c < s.c;
	}

};

struct Fenwick{
	int n; //Size of array
	vector<int> tree;

	void build(int m){ //Initializes the tree
		n = m;
		tree = vector<int>(m+1,0);
	}

	int read(int idx){ //Gives the sum [0,idx]
	    int sum = 0;
		idx++;
	    while (idx > 0){
	        sum += tree[idx];
	        idx -= (idx & -idx);
	    }
	    return sum;
	}

	void update(int k ,int val){ //Increases the k-th value
		k++;
	    while (k <= n){
	        tree[k] += val;
	        k += (k & -k);
	    }
	}
};

shop v[300010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> v[i].a >> v[i].b;
		++v[i].b;
		v[i].c = v[i].b - v[i].a;
	}
	sort(v, v+n);
	Fenwick F;
	F.build(m+1);
	int it = 0;
	for(int i = 1; i <= m; ++i){
		while(it < n and v[it].c < i) {
			F.update(v[it].a, 1);
			F.update(v[it].b, -1);
			++it;
		}
		int cur = n - it;
		for(int j = 1; j * i <= m; ++j) cur += F.read(j*i);
		cout << cur << endl;
	}
}
