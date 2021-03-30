#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
const int N = 1e5 + 5;
int ar[N + 5];

ordered_multiset seg_tree[N + N + N + N + 5];

void build(int pos, int L, int R){
  if (L == R){
    seg_tree[pos].insert(ar[L]);              
    return ;
  }
  int mid = (L + R) >> 1;
  int left = (pos << 1);
  int right = (left | 1);
  build(left, L, mid);
  build(right, mid + 1, R);
  for (auto it : seg_tree[left]){
    seg_tree[pos].insert(it);
  }
  for (auto it : seg_tree[right]){
    seg_tree[pos].insert(it);
  }                 
}

void modify(int pos, int L, int R, int ind, int er, int in){
  if (L > ind || R < ind){
    return ;
  }
  if (L == R){
    seg_tree[pos].erase(seg_tree[pos].begin());
    seg_tree[pos].insert(in);
    return ;
  }
  int mid = (L + R) / 2;
  int left = (pos << 1);
  int right = (left | 1);
  modify(left, L, mid, ind, er, in);
  modify(right, mid + 1, R, ind, er, in);
  seg_tree[pos].erase(seg_tree[pos].upper_bound(er));
  seg_tree[pos].insert(in);
}

int query(int pos, int L, int R, int l, int r, int val){
  if (L > r || R < l){
    return 0;
  }
  if (L >= l && R <= r){
    int sz = seg_tree[pos].size();
    int tmp = seg_tree[pos].order_of_key(val + 1);
    return sz - tmp;
  }
  int mid = (L + R) / 2;
  int left = (pos << 1);
  int right = (left | 1);
  int x = query(left, L, mid, l, r, val);
  int y = query(right, mid + 1, R, l, r, val);
  return x + y;
}

int main(){      
  
  return 0;
}