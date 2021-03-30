#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LG = ((int) log2(N)) + 1;

int n;
vector<int>g[N + 5];
bool vis[N + 5];
int depth[N + 5];
int par[N + 5];
int table[LG + 2][N + 5];

#warning (set depth of root node is 0)

void dfs(int u){ 
  vis[u] = true;
  table[0][u] = par[u];
  for (int v : g[u]) {
    if (vis[v] == false){
      depth[v] = depth[u] + 1;
      par[v] = u;   
      dfs(v);
    }
  }
}

void build_table(){
  for (int p = 1; p < LG; p++){
    for (int i = 0; i < n; i++){
      int x = table[p - 1][i];
      table[p][i] = (x == -1) ? -1 : table[p - 1][x]; 
    }
  }
}

int walk (int curr, int steps){
  for (int i = 0; i < LG; i++){
    if (steps & (1 << i)){
      curr = table[i][curr];
    }
  }
  return curr;   
}

int lca(int u, int v){
  if (depth[u] > depth[v]){
    swap(u, v);
  }
  v = walk(v, depth[v] - depth[u]);
  if (u == v){
    return u;
  }
  for (int i = LG - 1; i >= 0; i--){
    if (table[i][u] != table[i][v]){
      u = table[i][u];
      v = table[i][v];
    }
  }
  return table[0][u];
}

int main(){
  cin >> n;
  for (int i = 1; i < n; i++){
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  depth[0] = 0;
  par[0] = -1;   
  #warning(set depth of root node is 0)
  dfs(0);
  build_table();

  return 0;
}