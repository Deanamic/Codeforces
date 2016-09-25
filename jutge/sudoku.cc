// Resol un problema de sudokus del jutge.


#include <iostream>
#include <vector>
using namespace std;


typedef vector<int> VE;
typedef vector<VE> VVE;
typedef vector<VVE> VVVE;


VVE S(9, VE(9));
VVE fila, colu;
VVVE quad;


void f(int i, int j) {
  if (i == 9) {
    cout << endl;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) cout << (j ? " " : "") << S[i][j];
      cout << endl;
    }
    return;
  }

  if (j == 9) return f(i + 1, 0);
  
  if (S[i][j] != 0) return f(i, j + 1);

  for (int x = 1; x <= 9; ++x)
    if (not fila[i][x] and not colu[j][x] and not quad[i/3][j/3][x]) {
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
      S[i][j] = x;
      f(i, j + 1);
      S[i][j] = 0;
      fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = false;
    }
}


int main() {
  int n;
  cin >> n;
  cout << n << endl;
  while (n--) {
    fila = colu = VVE(9, VE(10, false));
    quad = VVVE(3, VVE(3, VE(10, false)));
    for (int i = 0; i < 9; ++i)
      for (int j = 0; j < 9; ++j) {
        char c;
        cin >> c;
        if (c == '.') S[i][j] = 0;
        else {
          int x = c - '0';
          S[i][j] = x;
          fila[i][x] = colu[j][x] = quad[i/3][j/3][x] = true;
        }
      }

    f(0, 0);
  }
}
