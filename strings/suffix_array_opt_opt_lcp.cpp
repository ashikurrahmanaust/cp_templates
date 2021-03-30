#include<bits/stdc++.h>

using namespace std;

void cus_sort(vector<int> &p, vector<int> &c){
  int n = p.size();
  vector<int>cnt(n);
  for (int v : c){
    cnt[v]++;
  }
  vector<int>pos(n);
  pos[0] = 0;
  for (int i = 1; i < n; i++){
    pos[i] = pos[i - 1] + cnt[i - 1];
  }
  vector<int> tmp(n);        
  for (int v : p){
    int i = c[v];
    tmp[pos[i]] = v;
    pos[i]++;
  }
  p = tmp;                 
}

void suffix_array_lcp(const string &str, int n){
  vector<int> c(n), p(n);
  {
    vector<pair<char, int>> ar(n);
    for (int i = 0; i < n; i++){
      ar[i] = {str[i], i};
    }
    sort(ar.begin(), ar.end());
    for (int i = 0; i < n; i++){
      p[i] = ar[i].second;
    }
    c[p[0]] = 0;
    for (int i = 1; i < n; i++){
      if (ar[i].first == ar[i - 1].first){
        c[p[i]] = c[p[i - 1]];
      } else {
        c[p[i]] = c[p[i - 1]] + 1;
      }
    }
  }
  for (int k = 0; (1 << k) < n; k++){
    for (int i = 0; i < n; i++){
      p[i] = (p[i] - (1 << k) + n) % n;
    }                    
    cus_sort(p, c);     
    vector<int> c_new(n);
    c_new[p[0]] = 0;
    for (int i = 1; i < n; i++){
      pair<int, int> curr = {c[p[i]], c[(p[i] + (1 << k)) % n]};
      pair<int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]};
      if (curr == prev){
        c_new[p[i]] = c_new[p[i - 1]];
      } else {
        c_new[p[i]] = c_new[p[i - 1]] + 1;
      }
    }              
    c = c_new; 
  }       
  // p is the suffix array
  // building lcp is following
  vector<int> lcp(n);
  for (int i = 0, k = 0; i < n - 1; i++){
    int pi = c[i];
    int j = p[pi - 1];
    while (str[i + k] == str[j + k]){
      k++;
    }
    lcp[pi] = k;
    k = max(0, k - 1);
  }
  for (int i = 0; i < n; i++){
    cout << p[i] << " ";
  }
  cout << "\n";
  for (int i = 1; i < n; i++){
    cout << lcp[i] << " ";
  }
  cout << "\n";
}

void suffix_array(string &str){
  str += '$';
  suffix_array_lcp(str, (int) str.size());
}

int main(){
  string str;
  cin >> str;
  suffix_array(str);
  return 0;
}