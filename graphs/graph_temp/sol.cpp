/***
*   author:   ashikur rahman
*   created:  30.12.2020 22:41:43
***/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
class graph {
public:
  struct edge {
    int from, to;
    T w;
    edge() {
      from = to = 0;
      w = 0;
    }
    edge(int f, int t) {
      from = f; to = t;
      w = 1;
    }
    edge(int f, int t, T _w) {
      from = f; to = t;
      w = _w;
    }
    void read() {
      cin >> from >> to >> w;
    }
  };
  int n, m;
  vector<vector<edge>> g;
  vector<edge> edges;
  graph(int _n, int _m) {
    n = _n; m = _m;
    g.clear();
    edges.clear();
    g.resize(n);
  }
  graph(int _n) {
    int _m = n - 1;
    g.clear();
    edges.clear();
    g.resize(n);
  }
  void add(const edge &e) {
    g[e.to].push_back(e);
    edges.push_back(e);   
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  graph<int> g(10, 15);
  return 0;
}