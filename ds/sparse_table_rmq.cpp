#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
const int LG = (int) log2(N) + 2;

int ar[N + 5];
int table[N + 5][LG + 2];

int main(){
  int n;
  cin >> n;
  for (int i = 0; i < n; i++){
    cin >> ar[i];
  }
  for (int i = 0; i < n; i++) {
    table[i][0] = ar[i];
  }
  // building table 0 based index
  for (int p = 1; p < LG; p++){
    for (int i = 0; i < n; i++){
      int nxt = i + (1 << (p - 1));
      if (nxt >= n){
        continue;
      }
      table[i][p] = min(table[i][p - 1], table[nxt][p - 1]);
    }
  }
  int q;
  cin >> q;
  while (q--){
    int l, r;
    cin >> l >> r;
    int mn = ar[l];
    // query for range
    for (int p = LG - 1; p >= 0; p--){
      if (l + (1 << p) - 1 <= r){
        mn = min(mn, table[l][p]);
        l = (l + (1 << p));
      }
    }
    cout << mn << "\n";
  }      
  return 0;
}