#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
map<int, int> bit;
int tree_size;

void modify(int ind, int val){
  while (ind <= tree_size){
    bit[ind] += val;
    ind += (ind & -ind);
  }
}

int query(int ind){
  int ret = 0;
  while (ind){
    ret += bit[ind];
    ind -= (ind & -ind);
  }
  return ret;
}

int main(){
  srand(time(0));
  int n = 1e9;
  int q = 5;
  long long sum = 0;
  tree_size = n;
  for (int i = n; i > n - q; i--){
    int x = rand() % 10;
    modify(i, x);
    sum += x;
    int y = get_sum(n);
    assert(y == sum); 
  }
  cout << "oK oK\n";
  return 0;
}