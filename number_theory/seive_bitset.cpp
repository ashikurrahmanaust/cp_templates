#include<bits/stdc++.h>

using namespace std;

const int N = 2e8;

bitset<N + 5> vis;
vector<int> primes;
int sz;

void seive(){  
  vis[0] = vis[1] = 1;
  for (int i = 4; i < N; i += 2){
    vis[i] = 1;
  }
  for (int i = 3; i * i < N; i += 2){
    if (!vis[i]){
      int inc = (i << 1);
      for (int j = i * i; j < N; j += inc){
        vis[j] = 1;        
      }
    }
  }                  
  primes.push_back(2);
  for (int i = 3; i < N; i += 2){
    if (!vis[i]){
      primes.push_back(i);
    }
  }
  sz = primes.size();                 
}

int main(){          
  std::clock_t c_start = std::clock();
  seive();
  cout << sz << "\n";
  std::clock_t c_end = std::clock();
  long double time_elapsed_ms = 1000.0 * (c_end-c_start) / CLOCKS_PER_SEC;
  std::cout << "CPU time used: " << time_elapsed_ms << " ms\n";
  return 0;
}