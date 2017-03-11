#include <bits/stdc++.h>
using namespace std;

double distance(double x, double y){
    return sqrt((50.0-x)*(50.0-x) + (50.0-y)*(50.0-y));
}

double distance1(double x, double y){
    return sqrt((50.0-x)*(50.0-x) + (100.0-y)*(100.0-y));
}

double angle(double x, double y){
    //cout << distance1(x,y) << endl;
    //cout << (distance1(x,y) *distance1(x,y) - 2500 - distance(x,y)*distance(x,y))/(2*50*distance(x,y)) << endl;
    if(x > 50){
        return acos((distance1(x,y) *distance1(x,y) - 2500 - distance(x,y)*distance(x,y))/(-2*50*distance(x,y))) *360/(2*M_PI) ;
    }
    else{
        return 360 - (acos((distance1(x,y)*distance1(x,y) - 2500 - distance(x,y)*distance(x,y))/(-2*50*distance(x,y)))*360/(2*M_PI));
    }
}

string check(double p, double x, double y){
        if(distance(x,y) > 50) return "white";
        cout << angle(x,y) << endl;
        if(p*3.6 >= angle(x,y)) return "black";
        return "white";

}

int main(){
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i){
        int p,x,y;
        cin >> p >> x >>y;
        cout << "Case #" << i <<": " << check(p,x,y) << endl;
    }
}
