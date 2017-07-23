//STATUS WA private

#include <bits/stdc++.h>
using namespace std;

double w1, l1, w2, l2;
const double EPS = 1e-6;

double ad(double cur) {
  if(cur < EPS) return 0;
  return cur*(w1 + (1-w1-l1) * l2) + ad(cur * (1- w1 - l1) * (1 - w2 - l2));
}

double da(double cur) {
  if(cur < EPS) return 0;
  return cur*(l1 + (1-w1-l1) * w2) + da(cur * (1 - w1 - l1) * (1 - w2 - l2));
}


int main() {
  cout.setf(ios::fixed);
  cout.precision(4);
  while(cin >> w1 >> l1 >> w2 >> l2) {
    double att1 = 0.5, lose1 = 0.5,  att2 = 0.5, att4 = 0.5;
    if(w1 + l1 > EPS) {
      att1 = w1/(w1+l1);
      lose1 = l1/(w1+w2);
    }

    if(w1 + w2 + l1 + l2 > EPS) {
        att2 = ad(1.0);
        att4 = da(1.0);
    }
    else {
        cout << 0.5 << endl;
        continue;
    }

    double att3 = 0.5, lose3 = 0.5;

    if(w2 + l2 > EPS) {
      att3 = w2/(w2+l2);
      lose3 = l2/(w2+l2);
    }
    else {
        cout << max(att1, 0.5) << endl;
        continue;
    }

    if(w1 + l1 < EPS) {
      if(att3 > 0.5) cout << lose3 << endl;
      else cout << 0.5 << endl;
      continue;
    }
    int p1a,p2a,p1d,p2d;

    {
        if(att4 > lose1) p2a = 1;
        else p2a = 0;
    }

    {
        if(att3 > 0.5) p2d = 1;
        else p2d = 0;
    }

    if(p2a and p2d) cout << max(att2, lose3) << endl;
    if(p2a and !p2d) cout << max(att2, 0.5) << endl;
    if(!p2a and p2d) cout << max(att1, lose3) << endl;
    if(!p2a and !p2d) cout << max(att1, 0.5) << endl;
  }
}
