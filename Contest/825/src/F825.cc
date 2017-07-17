#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

bool check(vector<string> & s) {
  int pad = 6;
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++) {
      bool h = true, v = true, dr = true, dl = true;
      for (int k = 0; k < 5; k++) {
        if (s[pad +i][pad+j+k] != 'X') h = false;
        if (s[pad +i+k][pad+j] != 'X') v = false;
        if (s[pad +i+k][pad+j+k] != 'X') dr = false;
        if (s[pad +i+k][pad+j-k] != 'X') dl = false;
      }
      if (h or v or dr or dl) return true;
    }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.precision(20);

  int pad = 6;
  vector<string> s(24, string(24, '0'));
  for (int i = 0; i < 10; i++) {
    string t;
    cin >> t;
    s[i+pad] = string(7,'0') + t +string(7,'0') ;
  }

  bool res = false;
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      char c = s[pad+i][pad+j];
      if (c == '.') {
        s[pad+i][pad+j] = 'X';
        if (check(s)) res = true;
        s[pad+i][pad+j] = c;
      }
    }
  }
  if (res) cout << "YES\n";
  else cout <<  "NO\n";


  return 0;
}
