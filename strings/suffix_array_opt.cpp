#include<bits/stdc++.h>

using namespace std;

void cus_sort(vector<pair<pair<int, int>, int>> &ar){
  int n = ar.size();
  {
    vector<int>cnt(n);
    for (pair<pair<int, int>, int> &v : ar){
      cnt[v.first.second]++;
    }
    vector<int>pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++){
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    vector<pair<pair<int, int>, int>> tmp(n);       
    for (pair<pair<int, int>, int> &v : ar){
      int i = v.first.second;
      tmp[pos[i]] = v;
      pos[i]++;
    }
    ar = tmp;
  }
  {
    vector<int>cnt(n);
    for (pair<pair<int, int>, int> &v : ar){
      cnt[v.first.first]++;
    }
    vector<int>pos(n);
    pos[0] = 0;
    for (int i = 1; i < n; i++){
      pos[i] = pos[i - 1] + cnt[i - 1];
    }
    vector<pair<pair<int, int>, int>> tmp(n);       
    for (pair<pair<int, int>, int> &v : ar){
      int i = v.first.first;
      tmp[pos[i]] = v;
      pos[i]++;
    }
    ar = tmp;
  } 
}

vector<int> suffix_array(const string &str, int n){
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
    vector<pair<pair<int, int>, int>> ar(n);
    for (int i = 0; i < n; i++){
      ar[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
    }
    cus_sort(ar);
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
  return p;
}

vector<int> suffix_array(string &str){
  str += '$';
  return suffix_array(str, (int) str.size());
}

int main(){
  string str;
  cin >> str;
  vector<int> ar = suffix_array(str);
  for (int v : ar){
    cout << v << " ";
  }
  cout << "\n";
  return 0;
}