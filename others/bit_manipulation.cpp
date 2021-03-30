#include<bits/stdc++.h>

using namespace std;

bool get_bit(int n, int k){
  return (n & (1 << k)) == 0 ? false : true;
}

void set_bit_self(int &n, int k){
  n |= (1 << k);
}

int set_bit(int n, int k){
  return n | (1 << k);
}

void reset_bit_self(int &n, int k){
  n &= (~(1 << k));
}            

int reset_bit(int n, int k){
  return n & (~(1 << k));
}

void toggle_bit_self(int &n, int k){
  n ^= (1 << k);  
}

int toggle_bit(int n, int k){
  return n ^ (1 << k);
}

int main(){
    
  return 0;
}