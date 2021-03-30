#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int LIM = 2e5 + 5;

template <typename T> inline T bigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T invMod (T A,T M = MOD){return bigMod(A,M-2,M);}

ll fac[LIM + 5];

void pre_cal(){
  fac[0] = fac[1] = 1;
  for (int i = 2; i < LIM; i++){
    fac[i] = (fac[i - 1] * (ll) i) % MOD;
  }
}

ll ncr(int n, int r){
  if (r > n){
    return 0;
  }
  ll x = fac[n];
  ll y = (fac[r] * fac[n - r]) % MOD;
  x *= invMod(y);
  return x % MOD;
}

int main(){
  pre_cal();
  
  return 0;
}