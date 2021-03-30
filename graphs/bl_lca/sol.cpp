/***
*   author:   ashikur rahman
*   created:  21.12.2020 23:24:12
***/

#include<bits/stdc++.h>

using namespace std;

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
  void build(const vector<vector<int>> &_g) {
    g = _g;
    dfs(root);
    for (int p = 1; p < lg; p++) {
      for (int i = 0; i < n; i++) {
        int x = ar[p - 1][i];
        ar[p][i] = (x == -1) ? -1 : ar[p - 1][x];
      }
    }
  }
  inline int walk(int u, int k) {
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
  vector<vector<int>> g;
  vector<vector<int>> ar;
  vector<bool> vis;
  vector<int> deep;
  int root = 0;
};

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      x--;
      g[i].push_back(x);
      g[x].push_back(i);
    }
  }
  LCA lc(n);
  lc.build(g);
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    cout << lc.lca(u, v) + 1 << "\n";
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  int t = 0;
  while (tc--) {
    cout << "Case " << ++t << ":\n";
    solve();
  }
  return 0;
}