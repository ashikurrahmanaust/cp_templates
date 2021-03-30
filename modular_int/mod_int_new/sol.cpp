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
  modular() : key(0) { }
  template<typename T>
  modular(const T &v) { key = normalize(v); }
  template <typename T>
  static inline int normalize(const T& x) {
    int v;
    if (-mod <= x && x < mod) { v = (int) x; }
    else { v = (int) (x % mod); }
    if (v < 0) { v += mod; }
    return v;
  }
  modular &operator += (const modular &rhs) { if ((key += rhs.key) >= mod) { key -= mod; } return *this; }
  modular &operator -= (const modular &rhs) { if ((key -= rhs.key) < 0) { key += mod; } return *this; }
  modular &operator *= (const modular &rhs) { const long long v = (long long) key * rhs.key; key = normalize(v); return *this; }
  modular &operator /= (const modular &rhs) { return *this *= inverse(rhs.key, mod); }
  modular &operator ++() { return *this += 1; }
  modular &operator --() { return *this -= 1; }
  modular operator ++(int) { modular &ret = *this; ret += 1; return ret; }
  modular operator --(int) { modular &ret = *this; ret -= 1; return ret; }
  bool operator == (const modular &rhs) { return key == rhs.key; };
  bool operator != (const modular &rhs) { return key != rhs.key; };
public:
  static int mod;
  int key;
};

bool operator == (const modular &lhs, const modular &rhs) { return lhs.key == rhs.key; }
bool operator != (const modular &lhs, const modular &rhs) { return lhs.key != rhs.key; }

modular operator + (const modular &lhs, const modular &rhs) { modular tmp = lhs; return tmp += rhs; }
modular operator - (const modular &lhs, const modular &rhs) { modular tmp = lhs; return tmp -= rhs; }
modular operator * (const modular &lhs, const modular &rhs) { modular tmp = lhs; return tmp *= rhs; }
modular operator / (const modular &lhs, const modular &rhs) { modular tmp = lhs; return tmp /= rhs; }

ostream & operator << (ostream &out, modular num) {
  num.key = modular::normalize(num.key);
  out << num.key;
  return out;
}
istream & operator >> (istream &in, modular &num) { 
  int tmp;
  in >> tmp;
  num.key = modular::normalize(tmp);
  return in;
}

int modular::mod = ;
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
modular power(const T &a, const U b) {
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);   
  return 0;
}