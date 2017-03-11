#include <bits/stdc++.h>
using namespace std;


struct punto {
	int x, y;
	bool operator <(const punto &p) const {
		return (x < p.x or (x == p.x and y < p.y));
	}
};


vector<punto> H;
vector<punto> P;

// Producto vectorial
// mayor que 0 si el giro es horario, igual 0 si es colinear,
// menor que 0 si es antihorario
int cross(const punto &O, const punto &A, const punto &B) {
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

// Devuelve la lista en sentido antihorario
// El ultimo punto es igual al primero
void convex_hull() {
	int n = P.size(), k = 0;
	H = vector<punto> (2*n);

	// ordenamos los puntos
	sort(P.begin(), P.end());

	// construimos la convexhull inferior
	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// construimos la convexhull superior
	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}
	H.resize(k-1);
}


int main(){
    long long n,m;
    double a;
    cin >> n >> m >> a;
    vector<int> v1,v2;
    if(n*m < ceil(a) or (a != int(a) and floor(a) != a-0.5)){
        return cout << -1 << endl, 0;
    }
    vector<int> p1(5),p2(5);
    bool cut = (a != int(a));
    if(a == 0.5){
        cout << 3 << endl;
        cout << "0 0\n0 1\n1 0\n";
        return 0;
    }
    a = ceil(a);
    bool reswap = 0;
    if(n < m) {
        swap(n,m);
        reswap = 1;
    }
    int height = 0;
    while(height * n < a) ++height;
    int c = a - (height-1) * n;
    if(cut){
        v1.push_back(1);
        v1.push_back(0);
        v2.push_back(0);
        v2.push_back(1);
    }
    else {
        v1.push_back(0);
        v2.push_back(0);
    }
    if(height*n == a){
        v1.push_back(0);
        v2.push_back(height);

        v1.push_back(n);
        v2.push_back(height);

        v1.push_back(n);
        v2.push_back(0);
    }
    else{
        v1.push_back(0);
        v2.push_back(height);

        v1.push_back(c);
        v2.push_back(height);

        v1.push_back(n);
        v2.push_back(height-1);

        v1.push_back(n);
        v2.push_back(1);

        v1.push_back(c);
        v2.push_back(0);


    }
    if(reswap) swap(v1,v2);
    P.resize(v1.size());
    for(int i = 0; i < v1.size(); ++i){
        P[i] = {v1[i],v2[i]};
    }
    convex_hull();
    cout << H.size() << endl;
    for(int i = H.size() -1;i >= 0; --i){
        cout << H[i].x << " " << H[i].y << endl;
    }

}
