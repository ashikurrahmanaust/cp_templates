#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


const int N = (int)1e7 + 5;
bool isPrime[N + 5];
int Phi[N + 5];

void gen_phi() {
  for ( int i = 0; i <= N; ++i ) Phi[i] = i;
  isPrime[0] = isPrime[1] = 1;
  for ( int i = 2; i <= N; ++i ){
    if ( isPrime[i] == 1 ) continue;
    for ( int j = i; j <= N; j += i ){
      Phi[j] = (Phi[j] / i) * (i - 1);    
      isPrime[j] = 1;
    }
  }                                                                        
}

int main() {                   
  gen_phi(); 
  return 0;
}
