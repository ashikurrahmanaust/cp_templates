#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 2;
bool vis[N + 5];
vector<int>primes;
int sz;

void seive(){
  vis[0] = vis[1] = true;
  for (int i = 4; i < N; i += 2){
    vis[i] = true;
  }
  for (int i = 3; i * i < N; i += 2){
    if (vis[i] == false){
      for (int j = i * i; j < N; j += (i << 1)){
        vis[j] = true;
      }
    }
  }
  primes.push_back(2);
  for (int i = 3; i < N; i += 2){
    if (vis[i] == false) primes.push_back(i);                                    
  }
  sz = primes.size();
}

vector<int> generate_divisor(int n){
  vector<int>ar;
  for (int i = 1; i * i <= n; i++){
    if (n % i == 0){
      ar.push_back(i);
      int j = n / i;
      if (i != j){
        ar.push_back(j);
      }
    }
  } 
  sort(ar.begin(), ar.end());
  return ar;
}

vector<int> generate_divisor(vector<pair<int, int>> &pp){
  vector<int>ar;
  ar.push_back(1);
  for (pair<int, int> p : pp){
    int csz = ar.size();
    for (int i = 0; i < csz; i++){
      int val = ar[i];
      for (int j = 0; j < p.second; j++){
        val *= p.first;
        ar.push_back(val);
      }
    }
  }
  sort(ar.begin(), ar.end());
  return ar;
}

int main(){
  seive();
  for (int v = 1; v <= 100000000; v++){
    int n = v;
    vector<pair<int, int>> pp;
    for (int i = 0; i < sz && primes[i] * primes[i] <= n; i++){
      if (n % primes[i] == 0){
        int cnt = 0;
        while (n % primes[i] == 0){
          n /= primes[i];
          cnt++;
        }
        pp.emplace_back(primes[i], cnt);
      }
    }
    if (n > 1){
      pp.emplace_back(n, 1);
    }                           
    if (v % 100000 == 0) cerr << v << "\n";
    assert(generate_divisor(pp) == generate_divisor(v));     
  }
  return 0;
}