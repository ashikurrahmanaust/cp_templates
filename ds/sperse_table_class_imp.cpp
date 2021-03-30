/***
*   author:   nondescript
*   created:  24.07.2020 11:14:58
***/

#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 5;

struct node {
  int val;
  node (){
    val = 0;
  }
  node (int _val){
    val = _val;
  }
  node operator + (const node &var) const & {
    return node(min(val, var.val));
  }
};

class sperse_table {
public:
  int n, lg;
  vector<vector<node>> table;
  sperse_table(int _n){
    n = _n;
    lg = (int) log2(n) + 2;
    table.clear();
    table.resize(n, vector<node> (lg));
  }

  void build(vector<int> &ar){
    for (int i = 0; i < n; i++){
      table[i][0] = node(ar[i]);
    }
    for (int p = 1; p < lg; p++){
      for (int i = 0; i < n; i++){
        int nxt = i + (1 << (p - 1));
        if (nxt >= n){
          continue;
        }
        table[i][p] = table[i][p - 1] + table[nxt][p - 1];
      }
    }
  }               
  node query(int l, int r){
    node ans = node(inf);
    for (int p = lg - 1; p >= 0; p--){
      if (l + (1 << p) - 1 <= r){
        ans = ans + table[l][p];
        l = (l + (1 << p));
      }
    }
    return ans;
  }
};

int main(){
  int n;
  cin >> n;
  vector<int> ar(n);
  for (int &v : ar){
    cin >> v;
  }
  sperse_table st(n);
  st.build(ar);
  int q;
  cin >> q;
  while (q--){
    int l, r;
    cin >> l >> r;
    cout << st.query(l, r).val << "\n";
  }
  return 0;
}