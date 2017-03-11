#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    while(cin >> n){
        int ans = 0;
        int sum = 0;
        int ant = 0;
        for(int i = 0; i < n; ++i){
            int x;
            cin >> x;
            if(x != 0){
                if(abs(ant) > (abs(sum + x)+1)/2){
                    ans = abs(ant);

                }
                else{
                    ans = (abs(sum + x)+1)/2;
                    ant = (abs(sum + x)+1)/2*(x/abs(x));
                }
                sum += x;
            }

        }
        cout << ans << endl;
    }
}
