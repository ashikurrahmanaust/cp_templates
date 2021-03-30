#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define endl '\n';
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const ll POSITIVE_INFINITY = 9223372036854775807;
const ll NEGATIVE_INFINITY = -9223372036854775807;
const ll MOD = 1000000007;
const ld PI = acos(-1.0);

template <typename T> inline T bigMod(T A,T B,T M = MOD){A %= M;T ret = 1;while(B){if(B & 1) ret = (ret * A) % M;A = (A * A) % M;B = B >> 1;}return ret;}
template <typename T> inline T invMod (T A,T M = MOD){return bigMod(A,M-2,M);}

const int N = 200005;

vector<int> lst = {101, 12343, 11311, 113, 12161, 43, 12323, 103, 12203, 11411};

#define hash my_hash

class hash{
public:
  const int mod = 19891; // use long long 999727999; // pick a good large prime
  const vector<int> pv = lst;
  vector<int>values;
  vector<int>mpow;
  int n;
  int m;           
  hash(){
    srand(time(0));
    random_shuffle(lst.begin(), lst.end());
    n = 1;
    values.clear();
    values.resize(n, 0);
    mpow.resize(n);
  }

  hash(int _n){
    srand(time(0));
    random_shuffle(lst.begin(), lst.end());
    if (_n > 10){
      cout << "can not be done\n";
      exit(0);
    }
    n = _n;
    values.clear();
    values.resize(n, 0);
    mpow.resize(n, 1);    
  }

  hash(int _n, string &str){
    if (_n > 10){
      cout << "can not be done\n";
      exit(0);
    }
    n = _n;
    m = str.size();
    values.clear();
    values.resize(n, 0);
    mpow.resize(n, 1);
    for (int j = 1; j < m; j++){
      for (int i = 0; i < n; i++){
        mpow[i] *= pv[i];
        mpow[i] %= mod;
      }
    }        
    for (int h = 0; h < n; h++){
      int x = values[h];
      int p = pv[h];
      for (char c : str){
        x *= p;
        x += c;
        x %= mod;
      }
      values[h] = x;
    }
  }

  void roll(char tail, char head){
    for (int h = 0; h < n; h++){
      int x = values[h];
      int bad = (mpow[h] * tail) % mod;
      x -= bad;
      x += mod;
      x %= mod;
      x *= pv[h];
      x += head;
      x %= mod;
      values[h] = x;   
    }
  }

  bool operator == (const hash& var) const {
    return values == var.values;    
  }
  bool operator != (const hash& var) const {
    return values != var.values;    
  }

  void dis(){
    for (int v : values){
      cout << v << " ";
    }
    cout << "\n";
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  while (tc--){
    string a, b;
    cin >> a >> b;
    int n = a.size();
    int m = b.size();
    hash h1 = hash(10, b);
    string tmp = a.substr(0, m);
    hash h2 = hash(10, tmp);
    vector<int> ans;
    if (h1 == h2){
      ans.push_back(1);
    }
    for (int i = m; i < n; i++){
      h2.roll(a[i - m], a[i]);
      if (h1 == h2){
        ans.push_back(i - m + 2);
      }
    }
    int sz = ans.size();
    if (sz == 0){
      cout << "Not Found\n";
    } else {
      cout << sz << "\n";
      for (int v : ans){
        cout << v << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}
