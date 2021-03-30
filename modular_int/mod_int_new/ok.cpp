/***
*   author:   ashikur rahman
*   created:  06.01.2021 13:48:17
***/

#include<bits/stdc++.h>

using namespace std;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}

class modular {
public:
  static int mod;
  int val;
  modular() { val = 0; }
  template<typename T>
  modular(T x) { val = normalize(x); }                                   
  template<typename T>
  static int normalize(T x) {
    int v;
    if (-mod <= x && x < mod) { v = (int) x; }
    else { v = (int) (x % mod); }
    if (v < 0) { v += mod; }
    return v;
  }
  modular operator ()() { return *this; }
  template<typename T> T operator () (modular &other) { return other; }
  template<typename T> modular operator + (T other) { return modular(val + other); }
  modular operator + (modular &other) { return modular(val + other.val - mod); }
  template<typename T> modular operator - (T other) { return modular(val - other); }
  modular operator - (modular &other) { return modular(val - other.val); }
  template<typename T> modular operator * (T other) { return modular((long long) val * other); }
  modular operator * (modular &other) { return modular((long long) val * other.val); }
  template<typename T> modular operator / (T other) { return modular((long long) val * inverse(other, mod)); }
  modular operator / (modular &other) { return modular((long long) val * inverse(other.val, mod)); }
  template<typename T> modular& operator += (T other) { val += other; val = modular::normalize(val); return *this; }
  modular& operator += (modular other) { val += other.val; val = modular::normalize(val); return *this; }
  template<typename T> modular& operator -= (T other) { val -= other; val = modular::normalize(val); return *this; }
  modular& operator -= (modular other) { val -= other.val; val = modular::normalize(val); return *this; } 
  template<typename T> modular& operator *= (T other) { *this = *this * other; return *this; }
  modular& operator *= (modular other) { *this = *this * other; return *this; }
  template<typename T> modular& operator /= (T other) { *this = *this / other; return *this; }
  modular& operator /= (modular other) { *this = *this / other; return *this; }
  modular& operator ++() { return *this += 1; }
  modular& operator --() { return *this -= 1; }
  modular operator ++(int) { modular res = *this; *this += 1; return res; }
  modular operator --(int) { modular res = *this; *this -= 1; return res; }
  modular operator -() { return modular(-val); }
};
bool operator == (const modular &lhs, const modular &rhs) { return lhs.val == rhs.val; }
template<typename T> bool operator == (modular &lhs, T rhs) { return lhs.val == rhs; }
template<typename T> bool operator == (T lhs, modular &rhs) { return lhs == rhs.val; }

bool operator != (const modular &lhs, const modular &rhs) { return lhs.val != rhs.val; }
template<typename T> bool operator != (const modular &lhs, T rhs) { return lhs.val != rhs; }
template<typename T> bool operator != (T lhs, const modular &rhs) { return lhs != rhs.val; }

template<typename T> modular operator + (T lhs, modular rhs) { return modular(lhs) + rhs; }
template<typename T> modular operator - (T lhs, modular rhs) { return modular(lhs) - rhs; } 
template<typename T> modular operator * (T lhs, modular rhs) { return modular(lhs) * rhs; }
template<typename T> modular operator / (T lhs, modular rhs) { return modular(lhs) / rhs; }                                                          

ostream & operator << (ostream &out, modular num) {
  num.val = modular::normalize(num.val);
  out << num.val;
  return out;
}                                   
istream & operator >> (istream &in, modular &num) { 
  int tmp;
  in >> tmp;
  num.val = modular::normalize(tmp);
  return in;
}

int modular::mod = (int) 1e9 + 7;
using mint = modular;

vector<mint> fac(1, 1);
vector<mint> inv_fac(1, 1);

mint C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  while ((int) fac.size() < n + 1) {
    fac.push_back(fac.back() * (int) fac.size());
    inv_fac.push_back(1 / fac.back());
  }
  return fac[n] * inv_fac[k] * inv_fac[n - k];
}

template<typename T, typename U>
modular power(const T a, const U b) {
  assert(b >= 0);
  mint x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
template<typename U>
modular power(modular &a, const U b) {
  assert(b >= 0);
  mint x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
const int sz = 20;
string ar;
mint dp[20][2][2][10][10][10][2][2][2];

mint F(int pos, int choto, int suru, int fd, int ld, int D, int ff, int lf, int mf) {
  if (pos >= sz) {
    if (ff && lf && mf) {
      return 1;
    }
    return 0;
  }
  if (suru && !ff) {
    return 0;
  }
  if (choto && dp[pos][choto][suru][fd][ld][D][ff][lf][mf] != -1) {
    return dp[pos][choto][suru][fd][ld][D][ff][lf][mf];    
  }
  mint sum = 0;
  if (choto) {
    for (int d = 0; d < 10; d++) {
      sum += F(pos + 1, choto, suru | (d > 0), fd, ld, D, (!suru && d == fd) ? ff | 1 : ff, (pos == sz - 1 && d == ld) ? lf | 1 : lf, (suru && pos < sz - 1 && D == d) ? mf | 1 : mf);
    }
  } else {
    int mx = ar[pos] - '0';
    for (int d = 0; d <= mx; d++) {
      sum += F(pos + 1, d < mx, suru | (d > 0), fd, ld, D, (!suru && d == fd) ? ff | 1 : ff, (pos == sz - 1 && d == ld) ? lf | 1 : lf, (suru && pos < sz - 1 && D == d) ? mf | 1 : mf);      
    }
  }
  return dp[pos][choto][suru][fd][ld][D][ff][lf][mf] = sum;
}

void solve() {
  long long n;
  int D;
  cin >> n >> D;
  ar = to_string(n);
  reverse(ar.begin(), ar.end());
  while((int) ar.size() < sz) {
    ar += '0';    
  }
  reverse(ar.begin(), ar.end());
  mint ans = 0;
  for (int f = 1; f < 10; f++) {
    for (int l = 1; l < 10; l++) {
      mint x = F(0, 0, 0, f, l, D, 0, 0, 0);
      mint y = F(0, 0, 0, l, f, D, 0, 0, 0);
      cout << x * y << " " << x << " " << y << "\n";
      ans += x * y;
    }
  }
  cout << ans << "\n";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc;
  cin >> tc;
  memset(dp, -1, sizeof dp);
  while (tc--) {
    solve();
  }
  return 0;
}