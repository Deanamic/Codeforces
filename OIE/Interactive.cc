#include <bits/stdc++.h>
using namespace std;

  
vector<int> safe(n,0);
int aux = -1;

void getans(int l, int r){
   if(r - l < 4){
    cout << ? << endl;
    int pos[4];
    for(int i = 0; i < 4; ++i){
      pos[i] = i+l;
      if(aux != -1 and pos[i] >= r) pos[i] = aux; 
    }
    cout << 1 << ' ';
    cout << pos[0] << endl;
  
    cout << 2 << ' '; 
    cout << pos[1] << ' ';
    cout << pos[2] << endl;

    cout << 1 << ' ';
    cout << pos[1] << endl; 
    
    cout << 2 << ' ';
    cout << pos[2] << ' ';
    cout << pos[3] << endl;

    //cout << endl;

    int ans1,ans2;
    cin >> ans1 >> ans2;
    cout << '!' << endl;
    if(ans1 == 0){
      if(ans2 == 0){
	cout << 1 << endl; //bug
      }
      if(ans2 == 1){
	cout << pos[3] << " >" << endl; 
      }
      if(ans2 == 2){
	cout << pos[3] << " <" << endl;
      }

    }
    if(ans1 == 1){
      if(ans2 == 0){
	cout << pos[0] << " <" << endl;
      }
      if(ans2 == 1){
	cout << pos[2] << " >" << endl;	
      }
      if(ans2 == 2){
	cout << pos[1] << " >" << endl;
      } 

    }
    if(ans1 == 2){
      if(ans2 == 0){
	cout << pos[0] << " >" << endl;
      }
      if(ans2 == 1){
	cout << pos[1] << " <" << endl
      }
      if(ans2 == 2){
	cout << pos[2] << " <" << endl;
      }
    }
   }
   else{
     


    }
}
  
int main(){
  string s;
  int n;
  cin >> s >> n;
  

}
