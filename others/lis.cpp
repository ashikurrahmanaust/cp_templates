/***
*   author:   ashikur rahman
*   created:  23.12.2020 11:36:33
***/

#include<bits/stdc++.h>

using namespace std;

template<typename T>
int lis(vector<T> &ar, int n) {
  vector<T> inc;
  vector<int> dp(n);
  for (int i = 0; i < n; i++) {
    int ind = upper_bound(inc.begin(), inc.end(), ar[i]) - inc.begin();
    if (ind < (int) inc.size()) {
      inc[ind] = ar[i];
    } else {
      inc.push_back(ar[i]);
    }
    dp[i] = ind + 1;
  }
  return *max_element(dp.begin(), dp.end()); 
}

template<typename T>
int lis(vector<T> &ar) {
  return lis(ar, (int) ar.size());
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  return 0;
}