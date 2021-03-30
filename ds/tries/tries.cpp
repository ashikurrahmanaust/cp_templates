/***
*   author:   ashikur rahman
*   created:  29.07.2020 17:12:05
***/

#include<bits/stdc++.h>

using namespace std;

const int N = 2000000;
const int MX_SZ = N * 10;

struct node{
  int finished;
  int next_node[27];
};

node nodes[MX_SZ];

const int root = 1;
int ptr = 2;

void add(string &str){
  int sz = str.size();
  int temp = root;
  for (int i = 0; i < sz; i++){
    int chr = (str[i] - 'a');
    if (nodes[temp].next_node[chr] == 0){
      nodes[temp].next_node[chr] = ptr++;
      //nodes[temp].finished = 1;
    }
    temp = nodes[temp].next_node[chr];
  }
  nodes[temp].finished = 1;
}

bool query(string &str){
  int sz = str.size();
  int temp = root;
  for (int i = 0; i < sz; i++){
    int chr = (str[i] - 'a');
    if (nodes[temp].next_node[chr] == 0){
      return false;
    }
    temp = nodes[temp].next_node[chr];
  }
  if (nodes[temp].finished != 0){
    return true;
  }
  return false;
}

void remove(string &str){
  int sz = str.size();
  int temp = root;
  for (int i = 0; i < sz; i++){
    int chr = (str[i] - 'a');
    if (nodes[temp].next_node[chr] == 0){
      return;
    }
    temp = nodes[temp].next_node[chr];
  }
  if (nodes[temp].finished != 0){
    nodes[temp].finished = 0;
  }                         
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
  return 0;
}