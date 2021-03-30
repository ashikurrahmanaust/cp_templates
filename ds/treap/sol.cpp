#include<bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>       
using namespace __gnu_pbds;

template<typename T>
class treap {
typedef tree<T, null_type, less_equal<T>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
public:
  ordered_set st;  
  treap() {
    st.clear();
  }
  void add(const T &v) {
    st.insert(v);  
  }
  void eliminate(const T &v) {
    auto it = st.upper_bound(v);
    assert(it != st.end() && *it == v);
    st.erase(it);
  }
  int count_smaller_than(const T &v) const {
    return st.order_of_key(v);
  }
  T kth_element(const int &k, const int &index = 0) const {
    return *st.find_by_order(k - index);
  }
  size_t size() const {
    return st.size();
  }                     
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  double st = clock();
  int n = (int) 1e6;
  vector<int> ord(n);
  iota(ord.begin(), ord.end(), 0);
  vector<treap<int>> ar(n);
  random_shuffle(ord.begin(), ord.end());
  for (int i = 0; i < n; i++) {
    ar[ord[i]].add(i + ord[i]);
  }
  for (int i = 0; i < n; i++) {
    cout << ar[i].kth_element(i % (int) ar[i].size()) << " ";
  }
  cout << "\n";
  double en = clock();
  cout << (en - st) / CLOCKS_PER_SEC << "\n";
  return 0;
}