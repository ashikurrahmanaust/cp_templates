#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 5;

int n, m;
vector<vector<int>> g;
vector<vector<int>>cap;

int bfs(int s, int d, vector<int> &par){
  vector<bool>vis(n, false);
  par[s] = -1;
  vis[s] = true;
  queue<pair<int, int>> q;
  q.push({s, inf});
  while (!q.empty()){
    int u = q.front().first;
    int flow = q.front().second;
    q.pop();
    for (int v : g[u]){
      if (vis[v] == false && cap[u][v]){
        vis[v] = true;
        par[v] = u;
        int new_flow = min(flow, cap[u][v]);
        if (v == d){
          return new_flow;
        }
        q.push({v, new_flow});
      }
    }
  }
  return 0;
}

int max_flow(){
  int total = 0;
  vector<int> par(n);
  int flow;
  int source = 0;
  int dest = n - 1;
  while ((flow = bfs(source, dest, par))){
    total += flow;              
    int curr = dest;
    while (curr != source){
      int prev = par[curr];
      cap[prev][curr] -= flow;
      cap[curr][prev] += flow;
      curr = prev;
    }
  }
  return total;
}
     
int main(){
  cin >> n >> m;
  g.clear();
  g.resize(n, vector<int> (n));
  cap.clear();
  cap.resize(n, vector<int>(n, 0));
  for (int i = 0; i < m; i++){
    int u, v, w;
    cin >> u >> v >> w;
    u--; v--;
    cap[u][v] = w;
    g[u].push_back(v);
  }
  cout << max_flow() << "\n";
  return 0;
}