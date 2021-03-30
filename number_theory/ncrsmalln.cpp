#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int LIM = 1e3 + 5;

ll ncr[LIM + 5][LIM + 5];

void pre_cal(){
  ncr[0][0] = 1;
  for (int i = 1; i < LIM; i++){
    for (int j = 0; j <= i; j++){
      if (j == 0 || j == i){
        ncr[i][j] = 1;
      } else {
        ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
      }
    }
  }
}

int main(){
  pre_cal();    

  return 0;
}