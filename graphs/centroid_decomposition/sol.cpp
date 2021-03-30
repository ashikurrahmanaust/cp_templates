/***
*   author:   ashikur rahman
*   created:  06.01.2021 21:59:23
***/

#include<bits/stdc++.h>

using namespace std;

class tree {
public:
  tree(int _n) {
    n = _n;
    dead.clear(); dead.resize(n, false);
    ans.clear(); ans.resize(n, '?');
    ss.clear(); ss.resize(n);
  }
  void get_tree(vector<vector<int>> &_g) {
    g = _g;
  }
  int get_center(int r) {
    function<void(int, int)> cal_ss = [&] (int u, int p) {
      ss[u] = 1;
      for (int v : g[u]) {
        if (v != p && !dead[v]) {
          cal_ss(v, u);
          ss[u] += ss[v];
        }
      }              
    };
    cal_ss(r, -1);
    int tot = ss[r];
    int half = tot >> 1;
    function<int(int, int)> dfs = [&] (int u, int p) {
      for (int v : g[u]) {
        if (v != p && !dead[v]) {
          if (ss[v] > half) {
            return dfs(v, u);
          }
        }
      }
      return u; 
    };
    return dfs(r, -1);
  }
  void all_centroid(int u) {
    int c = get_center(u);
    cerr << c << "\n";
    dead[c] = true;
    for (int v : g[c]) {
      if (!dead[v]) {
        all_centroid(v);
      }
    }
  }
  void solve() {
    all_centroid(0);
  }
private:
  int n;
  vector<vector<int>> g;
  vector<bool> dead;
  vector<char> ans;
  vector<int> ss;
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<vector<int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  tree ct(n);
  ct.get_tree(g);
  ct.solve();
  return 0;
}