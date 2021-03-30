#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
int bit[N + 5];
int tree_size;

int ar[N + 5];

void modify(int ind, int val){
  while (ind <= tree_size){
    bit[ind] += val;
    ind += (ind & -ind);
  }
}

int get_sum(int ind){
  int ret = 0;
  while (ind){
    ret += bit[ind];
    ind -= (ind & -ind);
  }
  return ret;
}

void build(int n){
  memset(bit, 0, sizeof bit);
  tree_size = n;
  for (int i = 1; i <= n; i++){
    modify(i, ar[i]);
  }
}

int main(){
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++){
    ar[i] = i + i;
  }                       
  build(n);
  for (int i = 1; i <= n; i++){
    cout << get_sum(i) << "\n";
  }
  return 0;
}