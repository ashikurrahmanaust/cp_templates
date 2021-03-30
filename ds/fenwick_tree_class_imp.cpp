#include<bits/stdc++.h>
using namespace std;

template<typename T>
class fenwick {
public:
  int sz;
  vector<T> tree;
  fenwick(int n){
    sz = n;
    tree.resize(sz + 1, {});
  }
  
  void modify(int ind, T val){
    while (ind <= sz){
      tree[ind] += val;
      ind += (ind & -ind);
    }
  }

  T query(int ind){
    T ret{};
    while (ind){
      ret += tree[ind];
      ind -= (ind & -ind);
    }
    return ret;
  }

  void build(vector<T> &ar){
    int n = ar.size();
    for (int i = 0; i < n; i++){
      modify(i + 1, ar[i]);
    } 
  }
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  fenwick <int> bit(n);
  for (int i = 0; i < n; i++){
    int x;
    cin >> x;
    bit.modify(x, 1);
  }               
  while (m--){
    int x;
    cin >> x;
    if (x > 0) {
      bit.modify(x, 1);
    } else {
      int k = abs(x);
      int lo = 1;
      int hi = n;
      int ind = n;
      while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (bit.query(mid) >= k){
          ind = min(ind, mid);
          hi = mid - 1;
        } else {
          lo = mid + 1;
        }
      }
      bit.modify(ind, -1);
    }
  }
  for (int i = 1; i <= n; i++){
    if (bit.query(i) > 0){
      cout << i << "\n";
      return 0;
    } 
  }
  cout << 0 << "\n";
  return 0;
}