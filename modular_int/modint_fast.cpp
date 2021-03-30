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
  template<typename T> modular operator + (T &other) { return modular(val + other); }
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
template<typename T> bool operator == (const modular &lhs, T rhs) { return lhs.val == rhs; }
template<typename T> bool operator == (T lhs, const modular &rhs) { return lhs == rhs.val; }

bool operator != (const modular &lhs, const modular &rhs) { return lhs.val != rhs.val; }
template<typename T> bool operator != (const modular &lhs, T rhs) { return lhs.val != rhs; }
template<typename T> bool operator != (T lhs, const modular &rhs) { return lhs != rhs.val; }

template<typename T> modular operator + (const T lhs, modular rhs) { return modular(lhs) + rhs; }
template<typename T> modular operator - (T lhs, modular rhs) { return modular(lhs) - rhs; } 
template<typename T> modular operator * (T lhs, modular rhs) { return modular(lhs) * rhs; }
template<typename T> modular operator / (T lhs, modular rhs) { return modular(lhs) / rhs; }                                                          

ostream & operator << (ostream &out, modular num) {
  out << num.val;
  num.val = modular::normalize(num.val);
  return out;
}                                   
istream & operator >> (istream &in, modular &num) { 
  int tmp;
  in >> tmp;
  num.val = modular::normalize(tmp);
  return in;
}

int modular::mod = 11;
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

int main(){
  mint x = 5;
  x = x + 3;
  return 0;
}