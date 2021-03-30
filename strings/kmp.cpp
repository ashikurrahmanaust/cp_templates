#include <bits/stdc++.h>

using namespace std;
                     
vector<int> build_failure_table(const string &pattern){
  int m = pattern.size();
  vector<int> table(m + 1);
  table[0] = table[1] = 0;
  for (int i = 2, j; i <= m; i++){
    j = table[i - 1];
    while (true){
      if (pattern[j] == pattern[i - 1]) {
        table[i] = j + 1;
        break;
      }
      if (j == 0){
        table[i] = 0;
        break;
      }
      j = table[j];
    }    
  }
  return table;
}

vector<int> kmp_matching(const string &txt, const string &pattern){
  vector<int> table = build_failure_table(pattern);
  int i = 0;
  int j = 0;
  int n = txt.size();
  int m = pattern.size();
  vector<int>pos;
  while (i < n){
    if (txt[i] == pattern[j]){
      i++; j++;
      if (j == m){
        pos.push_back(i - m);
        j = table[j];
      }
    } else if (j > 0){
      j = table[j];
    } else {
      i++;
    }
  }
  return pos;
}

void solve(){
  string a, b;
  cin >> a >> b;
  vector<int> res = kmp_matching(a, b);
  int sz = res.size();
  if (sz == 0){
    cout << "Not Found\n";
  } else {
    cout << sz << "\n";
    for (int v : res){
      cout << v + 1 << " ";
    }
    cout << "\n";
  }
  cout << "\n";
}

int main(){
  int tc;
  cin >> tc;
  while (tc--){
    solve();
  }  
  return 0;
}