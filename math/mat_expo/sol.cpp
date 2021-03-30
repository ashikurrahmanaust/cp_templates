/***
*   author:   an nodescript
*   created:  14.12.2020 12:03:13
***/

#include<bits/stdc++.h>

using namespace std;

const int mod = (int) 1e9 + 7;

template<int row, int colm>
class matrix {
public:         
  static const int n = row;
  static const int m = colm;
  array<array<int, m>, n> mat;

  matrix() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (i == j) {
          mat[i][j] = 1;
        } else {
          mat[i][j] = 0;
        }
      }
    }
  }                  
  matrix (const array<array<int, m>, n> &ar) {
    mat = ar;       
  }
  void zero() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        mat[i][j] = 0;
      }
    }
  }
  void get() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
      }
    } 
  }

  matrix operator + (const matrix& rhs) {
    assert(n == rhs.n && m == rhs.m);
    matrix<n, m> ret;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        ret.mat[i][j] = mat[i][j] + rhs.mat[i][j];
      }
    } 
    return ret;
  }
  matrix operator * (const matrix &rhs) {
    matrix<2, 2> ret;
    return ret;
  }
  int mult(int x, int y) {
    return int(((long long) x * y) % mod);
  }
  void add(int &x, int y) {
    x += y;
    if (x >= mod) {
      x -= mod;
    }
  }
  void dis() {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << mat[i][j] << " ";
      }
      cout << "\n";
    }
  }
};


template<typename T>
class modular {
public:

}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  matrix<4, 3> y = array{array<int, 3> {1, 2, 3}, array<int, 3> {4, 5, 6}, array<int, 3> {7, 8, 9}, array<int, 3> {10, 11, 12}};
  matrix<2, 4> x = array{array<int, 4> {1, 2, 3, 4}, array<int, 4> {5, 6, 7, 8}};
  y.dis();
  x.dis();
  matrix<2, 2> z = x * y;
  //matrix<2, 3> z = x * y;                               
  return 0;
}