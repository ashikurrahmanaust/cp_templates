#include<bits/stdc++.h>

using namespace std;

vector<int> manacher(const string &s) {
  int n = s.size();
  if (n == 0){
    return vector<int> ();
  }
  int m = n + n - 1;
  vector<int> table(m, 0);
  int l = -1, r = -1;
  for (int z = 0; z < m; z++) {
    int i = (z + 1) >> 1;
    int j = z >> 1;
    int p = (i >= r ? 0 : min(r - i, table[2 * (l + r) - z]));
    while (j + p + 1 < n && i - p - 1 >= 0) {
      if (!(s[j + p + 1] == s[i - p - 1])) {
        break;
      }
      p++;
    }
    if (j + p > r) {
      l = i - p;
      r = j + p;
    }
    table[z] = p;
  }               // odd index means the space and even means a character
  return table;  // contains how long the ith position can be extends in both side
}

vector<int> get_length(vector<int> table){
  int n = table.size();
  assert(n & 1);
  vector<int> len(n);
  for (int i = 0; i < n; i += 2){
    len[i] = table[i] + table[i] + 1;
  }
  for (int i = 1; i < n; i += 2){
    len[i] = table[i] + table[i];
  }
  return len;
}

int main(){
  string ar = "aabaa";
  for (char c : ar){
    cout << c << "   ";
  }
  cout << "\n";
  vector<int> v = manacher(ar);
  for (int i = 0; i < (int) v.size(); i++){
    cout << i << " ";
  }        
  cout << "\n";
  for (int i = 0; i < (int) v.size(); i++){
    cout << v[i] << " ";
  }
  cout << "\n";
  vector<int> len = get_length(v);
  for (int i = 0; i < (int) len.size(); i++){
    cout << len[i] << " ";    
  }
  cout << "\n";
  return 0;
}