/***
*   author:   ashikur rahman
*   created:  22.12.2020 12:16:20
***/

#include<bits/stdc++.h>

using namespace std;


template<typename T>
class LCA {
public:
  LCA(int _n) {
    n = _n;
    lg = 1;
    while ((1 << ++lg) < n);
    ar.clear(); vis.clear(); deep.clear();
    ar.resize(lg, vector<int> (n));
    vis.resize(n, false); deep.resize(n);
    #warning("initialize everything");
    ar[0][root] = -1;
    deep[root] = 0;
  }
  LCA(int _n, int r) {
    root = r;
    n = _n;
    lg = 1;
    while ((1 << ++lg) < n);
    ar.clear(); vis.clear();
    ar.resize(lg, vector<int> (n));
    vis.resize(n, false);
    #warning("initialize everything");
    ar[0][root] = -1;
    deep[root] = 0;
  }
  void dfs(int u) {
    vis[u] = true;
    for (int v : g[u]) {
      if (vis[v] == false) {
        ar[0][v] = u;
        deep[v] = deep[u] + 1;
        dfs(v);
      }
    }
  }
  void build(const vector<vector<T>> &_g) {
    g = _g;
    dfs(root);
    for (int p = 1; p < lg; p++) {
      for (int i = 0; i < n; i++) {
        int x = ar[p - 1][i];
        ar[p][i] = (x == -1) ? -1 : ar[p - 1][x];
      }
    }
  }
  int walk(int u, int k) {
    for (int i = lg - 1; i >= 0; i--) {
      if ((k & (1 << i))) {
        u = ar[i][u];
      }
    }
    return u;
  }
  int lca(int u, int v) {
    if (deep[u] > deep[v]) {
      swap(u, v);
    }
    v = walk(v, deep[v] - deep[u]);
    if (u == v) {
      return u;
    }
    for (int i = lg - 1; i >= 0; i--) {
      if (ar[i][u] != ar[i][v]) {
        u = ar[i][u];
        v = ar[i][v];
      }
    }
    assert(ar[0][u] == ar[0][v]);
    return ar[0][u];
  }
private:
  int n, lg;
  vector<vector<T>> g;
  vector<vector<int>> ar;
  vector<bool> vis;
  vector<int> deep;
  int root = 0;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}