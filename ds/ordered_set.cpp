#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

typedef tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
/*                         
  upper_bound in multiset returns the greater equal element.
*/

int main(){
  ordered_set st;
  for (int i = 0; i < 5; i++){
    st.insert(i);
    st.insert(i * i);   
  }
  // all elements
  for (auto it : st){
    cout << it << " ";
  }
  cout << "\n";
  int x = 3;
  int n = st.order_of_key(x);         // return number of elemenet stricktly less that x
  cout << n << "\n";
  int k = 4;
  cout << *st.find_by_order(k) << "\n";   // return the (k + 1)th pointer of the set  
  return 0;
}