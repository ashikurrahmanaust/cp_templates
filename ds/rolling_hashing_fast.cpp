#include<bits/stdc++.h>
using namespace std;

#define hash my_hash

int pv[] = {101, 12343, 11311, 113, 12161, 43, 12323, 103, 12203, 11411};
int mod[] = {31601, 31543, 31397, 31327, 31081, 30817, 30577, 30497, 30271, 30253};

void more_random(){
  srand(time(0));
  random_shuffle(pv, pv + 10);
  random_shuffle(mod, mod + 10);
}

class hash{
public:
  int values[10], mpow[10];
  int n;
  int m;           
  hash(){
    n = 1;
    for (int i = 0; i < 10; i++){
      values[i] = 0;
      mpow[i] = 1;
    }
  }

  hash(int _n){
    if (_n > 10){
      cout << "can not be done\n";
      exit(0);
    }
    n = _n;
    for (int i = 0; i < 10; i++){
      values[i] = 0;
      mpow[i] = 1;
    }    
  }

  hash(int _n, string &str){
    if (_n > 10){
      cout << "can not be done\n";
      exit(0);
    }
    n = _n;
    m = str.size();
    for (int i = 0; i < 10; i++){
      values[i] = 0;
      mpow[i] = 1;
    }
    for (int j = 1; j < m; j++){
      for (int i = 0; i < n; i++){
        mpow[i] *= pv[i];
        mpow[i] %= mod[i];
      }
    }        
    for (int h = 0; h < n; h++){
      int x = values[h];
      int p = pv[h];
      for (char c : str){
        x *= p;
        x += c;
        x %= mod[h];
      }
      values[h] = x;
    }
  }

  void roll(char tail, char head){
    for (int h = 0; h < n; h++){
      int x = values[h];
      int md = mod[h];
      int bad = (mpow[h] * tail) % md;
      x -= bad;
      x += md;
      x %= md;
      x *= pv[h];
      x += head;
      x %= md;
      values[h] = x;   
    }
  }

  bool operator == (const hash& var) const &{
    for (int i = 0; i < n; i++){
      if (values[i] != var.values[i]){
        return false;
      }
    }
    return true;
  }
  bool operator != (const hash& var) const &{
    for (int i = 0; i < n; i++){
      if (values[i] == var.values[i]){
        return false;
      }
    }
    return true;
  }

  void dis(){
    for (int v : values){
      cout << v << " ";
    }
    cout << "\n";
  }
};


int main(){
  more_random();
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
