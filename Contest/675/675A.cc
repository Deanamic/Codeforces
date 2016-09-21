#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <cmath>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b == a) {cout << "YES" << endl; return 0;}
    if (b > a) {
        if (c > 0 and (b-a)%c == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (b < a) {
        if (c < 0 and abs(b-a)%abs(c) == 0) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    
}
