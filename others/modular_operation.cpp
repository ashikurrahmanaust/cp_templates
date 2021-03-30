#include<bits/stdc++.h>
using namespace std;
                    
typedef long long ll;

const int MOD = 1000000007;

template <typename T> inline T big_mod (T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (T) (((ll)ret * A) % M);A = (T) (((ll)A * A) % M);B = B >> 1;}return ret;}
template <typename T> inline T inv_mod (T A,T M = MOD){return big_mod(A,M-2,M);}

void add_self(int &x, int y){
  x += y;
  if (x >= MOD){
    x -= MOD;
  }
}
void sub_self(int &x, int y){
  x -= y;
  if (x < 0){
    x += MOD;
  }
}
void mult_self(int &x, int y){      
  x = (int) (((ll) x * y) % MOD);
}
void div_self(int &x, int y){
  int inv = inv_mod(y);
  mult_self(x, inv);
}   
int main(){
      
  return 0;
}