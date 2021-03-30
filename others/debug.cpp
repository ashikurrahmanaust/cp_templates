/***
*   author:   nondescript
*   created:  30.10.2020 22:12:41
***/

#include<bits/stdc++.h>

using namespace std;

string to_string(string str) {
  return str;
}
string to_string(bool n) {
  return (n == true ? "true" : "false");
}
template<typename T, typename U>
string to_string(pair<T, U> p) {
  return "{" + to_string(p.first) + " " + to_string(p.second) + "}"; 
}
template<typename T, typename U, typename V>
string to_string(pair<T, pair<U, V>> p) {
  return "{" + to_string(p.first) + " " + to_string(p.second.first) + " " + to_string(p.second.second) + "}";
} 
template<typename T>
string to_string(vector<T> ar) {
  string res = "";
  for (int i = 0; i < (int) ar.size(); i++) {
    if (i > 0) {
      res += " ";
    }
    string ind = to_string(i);
    res += "(" + ind + ")" + to_string(ar[i]);
  }
  return res;
}

template<typename T>
void debug(T head) {
  cerr << to_string(head) << " ";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int a = 5;
  long long b = 10;
  double c = 1.2343;
  char d = 'a';
  string e = "abcde";
  pair<int, bool> f = {1, true};
  vector<int> g = {1, 2, 3};                 
  return 0;
}