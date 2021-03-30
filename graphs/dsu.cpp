#include<bits/stdc++.h>
using namespace std;

vector<int>par;

void init(int n){
  par.clear();
  par.resize(n + 1);
  iota(par.begin(), par.end(), 0);
}

int find_par(int x){
  return par[x] = (x == par[x]) ? x : find_par(par[x]);
} 

bool unite(int x, int y){
  int px = find_par(x);
  int py = find_par(y);
  if (px == py){
    return false;
  }
  par[py] = px;
  return true;
}

int main(){
  init(5);

  return 0;
}