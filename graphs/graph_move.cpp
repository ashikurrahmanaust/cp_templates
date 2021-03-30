#include<bits/stdc++.h>

using namespace std;


const int dx[] = {0, -1, 0, 1};
const int dy[] = {-1, 0, 1, 0};
/*
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};                  
*/
const int mv = 4;

int main(){
  function < void (int, int) > bfs = [&] (int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    while (!q.empty()){
      auto var = q.front();
      q.pop();
      int ux = var.first;
      int uy = var.second;
      for (int i = 0; i < mv; i++){   // change move size if require
        int vx = ux + dx[i];
        int vy = uy + dy[i];
        if (true){
          q.push({vx, vy});
        }
      }
    }
  };
  bfs(0, 0);
  return 0;
}