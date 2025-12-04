#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<string> vs;
bool checkSurround (vs& inputs, int col, int row);

int main() {
  long a, b, c, d, count1=0, count2=0;
  string s1, s2, s3;
  char c1, c2, c3;
  
  vs inputs;
  while(cin >> s1) {
    inputs.push_back(s1);
  }
  
  c = s1.length();
  d = inputs.size();
  
  for(int i = 0; i < d; i++){
    for(int j = 0; j < c; j++){
      if(checkSurround(inputs, i, j)) count1++;
    }
  }
  count2 = count1;
  while(a!=count2) {
    a = count2;
    for(int i = 0; i < d; i++){
      for(int j = 0; j < c; j++){
        if(checkSurround(inputs, i, j)) count2++;
      }
    }
  }
  
  cout << count1 << ' ' << count2;
  
  return 0;
}

bool checkSurround (vs& inputs, int col, int row) {
  int count = 0;
  if(inputs[col][row] =='.') return false;
  for(int i = col-1; i <= col + 1; i++){
    for(int j = row-1; j <= row + 1; j++){
      if(i >= 0 && j >= 0 && i < inputs.size() && j < inputs[0].length()) {
        if(inputs[i][j] == '@') count++;
      }
    }
  }
  if(count >= 5) return false;
  inputs[col][row] = '.';
  return true;
}
