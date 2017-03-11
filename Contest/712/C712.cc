#include <bits/stdc++.h>
using namespace std;

int main (){
    int x,y;
    cin >> x >> y;
    int s1,s2,s3;

    s1 = s2 = s3 = min(x,y);
    y = max(x,y);
    x = s1;
    int ans = 0;
    while(y != s1 or y != s2 or y != s3){
        if(s1 <= s2 and s1 <= s3){
            s1 = min(y, s2 + s3 - 1);
        }
        else if (s2 <= s1 and s2 <= s3){
            s2 = min(y, s1 + s3 - 1);
        }
        else{
            s3 = min(y, s1 + s2 - 1);
        }
        ++ans;
    }
    cout << ans << endl;
}
